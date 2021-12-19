#include <iostream>
#include <string>
using namespace std;

// khai báo lớp cha: Vehicles
class Vehicles
{
protected:
    string fullNameOfRenter;
    double rentalHours;

public:
    void input()
    {
        cin.ignore();
        cout << "\nNhap ho ten nguoi thue: ";
        getline(cin, fullNameOfRenter);
        cout << "\nSo gio thue xe: ";
        cin >> rentalHours;
    }
    void output()
    {
        cout << "\nHo ten nguoi thue: " << fullNameOfRenter;
        cout << "\nSo gio thue xe: " << rentalHours;
    }
};

// khai báo lớp con: Bike & Motorbycle
class Bike : public Vehicles // lớp xe đạp
{
public:
    double calculateRent() // tính tiền thuê
    {
        return 10000 + ((rentalHours - 1) * 8000); // giờ đầu tiên 10000, các giờ sau 8000
    }
};

class Motorbike : public Vehicles // lớp xe máy
{
private:
    int type;
    string licensePlate;

public:
    void input()
    {
        Vehicles::input();
        cout << "\nNhap loai xe can thue (100 - 250 phan khoi): ";
        cin >> type;
        cin.ignore();
        cout << "\nNhap bien so xe: ";
        getline(cin, licensePlate);
    }

    void output()
    {
        Vehicles::output();
        cout << "\nLoai xe: " << type << " phan khoi";
        cout << "\nBien so xe: " << licensePlate;
    }

    double calculateRent()
    {

        double sum = 0;  // số tiền giờ đầu tiên
        if (type == 100) // 100 phan khoi
            sum = 150000;
        else // 250 phan khoi
            sum = 200000;
        return sum + ((rentalHours - 1) * 100000);
    }

    int getType()
    {
        return type;
    }

    double getRentalHours()
    {
        return rentalHours;
    }
};

// * phương thức xuất tất cả thông tin thuê xe
void outputBoth(Bike *bikeList, int n, Motorbike *motorbikeList, int m)
{
    // xuất xe đạp
    cout << "\n\n\t\tDANH SACH XE DAP\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\n\tTHONG TIN XE DAP " << i + 1 << endl;
        bikeList[i].output();
    }

    // xuất xe máy
    cout << "\n\n\t\tDANH SACH XE MAY\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\n\n\tTHONG TIN XE MAY " << i + 1 << endl;
        motorbikeList[i].output();
    }
}

// * phương thức tính tổng tiền thuê xe đạp - xe máy
double totalAmountBoth(Bike *bikeList, int n, Motorbike *motorbikeList, int m)
{
    double sum = 0;
    // tiền xe đạp
    for (int i = 0; i < n; i++)
    {
        sum += bikeList[i].calculateRent();
    }

    // tiền xe máy
    for (int i = 0; i < m; i++)
    {
        sum += motorbikeList[i].calculateRent();
    }
    return sum;
}

// * phương thức tính tổng tiền thuê xe máy loại 250 phân khối
double totalAmountMotorbikeRental250(Motorbike *motorbikeList, int m)
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (motorbikeList[i].getType() == 250)
        {
            sum += 200000 + (motorbikeList[i].getRentalHours() - 1) * 100000;
        }
    }
    return sum;
}

void menu(Bike *bikeList, int n, Motorbike *motorbikeList, int m)
{
    int choose;
    bool exit = false;

    do
    {
        system("cls");
        cout << "--------------------- CHUONG TRINH QUAN LI ---------------------";
        cout << "\n|     1. Nhap danh sach thue XE DAP - XE MAY";
        cout << "\n|     2. Xuat tat ca thong tin thue xe";
        cout << "\n|     3. Tinh tong tien cho thue xe dap va xe may";
        cout << "\n|     4. Xuat tat ca thong tin den viec cho thue xe dap";
        cout << "\n|     5. Tinh tong so tien cho thue xe may loai 250 phan khoi";
        cout << "\n|     0. Thoat chuong trinh";
        cout << "\n--------------------------- <3<3<3 ------------------------------";

        cout << "\n     Nhap lua chon: ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            bool exit2 = false;
            do
            {
                system("cls");
                cout << "--------------------------- :3:@:# ------------------------------";
                cout << "\n|     1. Thue XE DAP";
                cout << "\n|     2. Thue XE MAY";
                cout << "\n|     0. Tro ve";
                cout << "\n--------------------------- <3<3<3 ------------------------------";

                cout << "\n     Nhap lua chon: ";
                cin >> choose;
                switch (choose)
                {
                case 1:
                {
                    Bike bike;
                    cout << "\n\n\t\tNHAP THONG TIN THUE XE DAP\n";
                    bike.input();
                    bikeList[n] = bike;
                    n++;
                    break;
                }
                case 2:
                {
                    Motorbike motorbike;
                    cout << "\n\n\t\tNHAP THONG TIN THUE XE MAY\n";
                    motorbike.input();
                    motorbikeList[m] = motorbike;
                    m++;
                    break;
                }
                case 0:
                {
                    exit2 = true;
                    break;
                }
                default:
                    cout << "\n\n\t\tKhong hop le\n";
                    system("pause");
                    break;
                }
            } while (!exit2);
            break;
        }
        case 2:
            cout << "\n\n\t\tTAT CA THONG TIN THUE XE DAP - XE MAY\n";
            outputBoth(bikeList, n, motorbikeList, m);
            system("pause");
            break;
        case 3:
            cout << "\n\n\t\tTONG TIEN THUE XE DAP VA XE MAY\n";
            cout << "\nTong tien thue xe: " << (size_t)totalAmountBoth(bikeList, n, motorbikeList, m);
            system("pause");
            break;
        case 4:
            cout << "\n\n\t\tTAT CA THONG TIN THUE XE DAP\n";
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\tTHONG TIN XE DAP " << i + 1 << endl;
                bikeList[i].output();
            }
            system("pause");
            break;
        case 5:
            cout << "\n\n\t\tTONG TIEN THUE XE MAY LOAI 250 PHAN KHOI\n";
            cout << "\nTong tien thue xe: " << (size_t)totalAmountMotorbikeRental250(motorbikeList, m);
            system("pause");
            break;
        case 0:
            exit = true;
            cout << "\n\n\t\tThoat thanh cong\n";
            system("pause");
            break;
        default:
            cout << "\n\n\t\tKhong hop le\n";
            system("pause");
            break;
        }
    } while (!exit);
}

int main()
{
    Bike *bike = new Bike[100]; // vẫn là đối tượng giá trị -> đây là tạo mảng động mà quản lí bởi con trỏ
    Motorbike *motorbike = new Motorbike[100];
    int n = 0, m = 0;
    menu(bike, n, motorbike, m);
    delete[] bike;
    delete[] motorbike;
    return 0;
}