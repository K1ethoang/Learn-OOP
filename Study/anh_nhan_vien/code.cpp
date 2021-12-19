#include <iostream>
#include <algorithm>
using namespace std;

// khai báo cấu trúc lớp Người lao động
class Workers
{
private:
    string fullName;
    int age;
    string sex;
    string address;
    string phone;

public:
    Workers();
    void input();
    void output();
    ~Workers();
};
// hàm tạo
Workers::Workers()
{
    this->fullName = "";
    this->age = 0;
    this->sex = "";
    this->address = "";
    this->phone = "";
}
// hàm nhập
void Workers::input()
{
    fflush(stdin);
    cout << "\nNhap ho ten: ";
    getline(cin, fullName);
    cout << "\nNhap tuoi: ";
    cin >> age;
    fflush(stdin);
    cout << "\nNhap gioi tinh: ";
    getline(cin, sex);
    cout << "\nNhap dia chi: ";
    getline(cin, address);
    cout << "\nNhap so dien thoai: ";
    getline(cin, phone);
}
// hàm xuất
void Workers::output()
{
    cout << "\nHo ten: " << fullName;
    cout << "\ntuoi: " << age;
    cout << "\nGioi tinh: " << sex;
    cout << "\nDia chi: " << address;
    cout << "\nSo dien thoai: " << phone;
}
// hàm huỷ
Workers::~Workers()
{
}

// * nhân viên sửa ống nước
class Plumber : public Workers
{
private:
    float hoursOfRepairAmount; // số giờ sữa chữa
public:
    void setHoursOfRepairAmount(float data);
    float getHoursOfRepairAmount();
    float salaryAmount();
};

void Plumber::setHoursOfRepairAmount(float data)
{
    this->hoursOfRepairAmount = data;
}

float Plumber::getHoursOfRepairAmount()
{
    return hoursOfRepairAmount;
}

// hàm tính tiền lương
float Plumber::salaryAmount()
{
    return hoursOfRepairAmount * 50000;
}

// * nhân viên giao hàng
class Deliver : public Workers
{
private:
    int deliveryQuantity; // số lượng hàng giao
public:
    void setDeliveryQuantity(int data);
    int getDeliveryQuantity();

    float salaryAmount();
};

void Deliver::setDeliveryQuantity(int data)
{
    this->deliveryQuantity = data;
}

int Deliver::getDeliveryQuantity()
{
    return deliveryQuantity;
}

float Deliver::salaryAmount()
{
    return deliveryQuantity * 33.500;
}

// * nhân viên xe ôm
class Driver : public Workers
{
private:
    float runKilometers; // số km chạy
public:
    void setRunKilometers(float data);
    float getRunKilometers();
    float salaryAmount();
};

void Driver::setRunKilometers(float data)
{
    this->runKilometers = data;
}

float Driver::getRunKilometers()
{
    return runKilometers;
}

float Driver::salaryAmount()
{
    return runKilometers * 10000;
}

// ! function overloading
// hàm tính tổng tiền lương các nhân viên sửa ống nước
double sumOfSalary(Plumber *plumberList[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += plumberList[i]->salaryAmount();
    }
    return sum;
}
// hàm tính tổng tiền lương các nhân viên giao hàng
double sumOfSalary(Deliver *deliverList[], int m)
{
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += deliverList[i]->salaryAmount();
    }
    return sum;
}
// hàm tính tổng tiền lương các nhân viên xe ôm công nghệ
double sumOfSalary(Driver *driverList[], int l)
{
    double sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += driverList[i]->salaryAmount();
    }
    return sum;
}

// sắp xếp danh sách nhân viên SỬA ỐNG NƯỚC giảm dần
void sortTheListInDescendingOrderBySalary(Plumber *plumberList[], int n)
{
    // Insertion sort
    for (int i = 1; i < n; i++)
    {
        Plumber *key = plumberList[i];
        int j = i - 1;
        while (j >= 0 && plumberList[j]->salaryAmount() < key->salaryAmount())
        {
            *(plumberList + j + 1) = *(plumberList + j);
            j--;
        }
        plumberList[j + 1] = key;
        delete key;
    }
}

// sắp xếp danh sách nhân viên GIAO HÀNG giảm dần theo lương
void sortTheListInDescendingOrderBySalary(Deliver *deliverList[], int m)
{
    // Bubble sort
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            if (deliverList[j]->salaryAmount() < deliverList[j + 1]->salaryAmount())
                swap(deliverList[j], deliverList[j + 1]);
        }
    }
}

// sắp xếp danh sách nhân viên XE ÔM CÔNG NGHỆ giảm dần theo lương
void sortTheListInDescendingOrderBySalary(Driver *driverList[], int l)
{
    // Selection sort
    for (int i = 0; i < l - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < l; j++)
        {
            if (driverList[maxIndex]->salaryAmount() < driverList[j]->salaryAmount())
                maxIndex = j;
        }
        if (maxIndex != i)
            swap(driverList[i], driverList[maxIndex]);
    }
}

// thiết kế menu xử lí
void menu(Plumber *plumberList[], Deliver *deliverList[], Driver *driverList[], int n, int m, int l)
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "--------------------- CHUONG TRINH QUAN LI ---------------------";
        cout << "\n|     1. Nhap thong tin nhan vien SUA ONG NUOC";
        cout << "\n|     2. Nhap thong tin nhan vien GIAO HANG";
        cout << "\n|     3. Nhap thong tin nhan vien XEM OM CONG NGHE";
        cout << "\n|     4. Xuat danh sach thong tin nhan vien SUA ONG NUOC";
        cout << "\n|     5. Xuat danh sach thong tin nhan vien GIAO HANG";
        cout << "\n|     6. Xuat danh sach thong tin nhan vien XEM OM CONG NGHE";
        cout << "\n|     7. Tong tien luong cac nhan vien";
        cout << "\n|     8. Sap xep danh sach cac loai nhan vien giam dan theo luong";
        cout << "\n|     0. Thoat chuong trinh";
        cout << "\n--------------------------- <3<3<3 ------------------------------";

        cout << "\n     Nhap lua chon: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
        {
            Plumber *plumber = new Plumber(); // đối tượng con trỏ
            cout << "\n\n\t\tNHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
            plumber->input();
            double hours;
            cout << "\nNhap so gio sua: ";
            cin >> hours;
            plumber->setHoursOfRepairAmount(hours);
            // thêm đối tượng con trỏ "plumber" vào danh sách con trỏ "plumberList"
            plumberList[n] = plumber;
            n++;
            break;
        }
        case 2:
        {
            Deliver *deliver = new Deliver(); // đối tượng con trỏ
            cout << "\n\n\t\tNHAP THONG TIN NHAN VIEN GIAO HANG\n";
            deliver->input();
            int goods; // hàng giao
            cout << "\nNhap so hang giao: ";
            cin >> goods;
            deliver->setDeliveryQuantity(goods);
            // thêm đối tượng con trỏ "deliver" vào danh sách con trỏ "deliverList"
            deliverList[m] = deliver;
            m++;
            break;
        }
        case 3:
        {
            Driver *driver = new Driver(); // đối tượng con trỏ
            cout << "\n\n\t\tNHAP THONG TIN NHAN VIEN XE OM CONG NGHE\n";
            driver->input();
            float kilometers;
            cout << "\nNhap so km chay: ";
            cin >> kilometers;
            driver->setRunKilometers(kilometers);
            // thêm đối tượng con trỏ "driver" vào danh sách con trỏ "driverList"
            driverList[l] = driver;
            l++;
            break;
        }
        case 4:
        {
            cout << "\n\n\t\tDANH SACH THONG TIN NHAN VIEN\n";
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\tTHONG TIN NHAN VIEN SUA ONG NUOC " << i + 1 << endl;
                plumberList[i]->output();
                cout << "\nSo gio sua chua: " << plumberList[i]->getHoursOfRepairAmount();
                cout << "\nTien luong: " << (size_t)plumberList[i]->salaryAmount();
            }
            cout << "\n\n\t\tTONG TIEN LUONG: " << (size_t)sumOfSalary(plumberList, n);
            system("pause");
            break;
        }
        case 5:
        {
            cout << "\n\n\t\tDANH SACH THONG TIN NHAN VIEN\n";
            for (int i = 0; i < m; i++)
            {
                cout << "\n\n\tTHONG TIN NHAN VIEN GIAO HANG " << i + 1;
                deliverList[i]->output();
                cout << "\nSo hang giao: " << deliverList[i]->getDeliveryQuantity();
                cout << "\nTien luong: " << (size_t)deliverList[i]->salaryAmount();
            }
            cout << "\n\n\t\tTONG TIEN LUONG: " << (size_t)sumOfSalary(deliverList, m);
            system("pause");
            break;
        }
        case 6:
        {
            cout << "\n\n\t\tDANH SACH THONG TIN NHAN VIEN\n";
            for (int i = 0; i < l; i++)
            {
                cout << "\n\n\tTHONG TIN NHAN VIEN XE OM CONG NGHE " << i + 1;
                driverList[i]->output();
                cout << "\nSo km chay: " << driverList[i]->getRunKilometers();
                cout << "\nTien luong: " << (size_t)driverList[i]->salaryAmount();
            }
            cout << "\n\n\t\tTONG TIEN LUONG: "
                 << (size_t)sumOfSalary(driverList, l);
            system("pause");
            break;
        }
        case 7:
            cout << "\n\n\t\tTONG TIEN LUONG CONG TY CAN TRA HANG THANG\n";
            cout << "\nNhan vien sua ong nuoc: " << (size_t)sumOfSalary(plumberList, n);
            cout << "\nNhan vien giao hang: " << (size_t)sumOfSalary(deliverList, m);
            cout << "\nNhan vien xe om cong nghe: " << (size_t)sumOfSalary(driverList, l);
            cout << "\n -> Tong: " << (size_t)(sumOfSalary(plumberList, n) + sumOfSalary(deliverList, m) + sumOfSalary(driverList, l));
            system("pause");
            break;
        case 8:
            cout << "\n\n\t\tDANH SACH GIAM DAN LUONG NV SUA ONG NUOC\n";
            sortTheListInDescendingOrderBySalary(plumberList, n);
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\tTHONG TIN NHAN VIEN SUA ONG NUOC " << i + 1;
                plumberList[i]->output();
                cout << "\nSo gio sua chua: " << plumberList[i]->getHoursOfRepairAmount();
                cout << "\nTien luong: " << (size_t)plumberList[i]->salaryAmount();
            }
            cout << "\n\n\t\tDANH SACH GIAM DAN LUONG NV GIAO HANG\n";
            sortTheListInDescendingOrderBySalary(deliverList, m);
            for (int i = 0; i < m; i++)
            {
                cout << "\n\n\tTHONG TIN NHAN VIEN GIAO HANG " << i + 1;
                deliverList[i]->output();
                cout << "\nSo hang giao: " << deliverList[i]->getDeliveryQuantity();
                cout << "\nTien luong: " << (size_t)deliverList[i]->salaryAmount();
            }
            cout << "\n\n\t\tDANH SACH GIAM DAN LUONG NV XE OM CONG NGHE\n";
            sortTheListInDescendingOrderBySalary(driverList, l);
            for (int i = 0; i < l; i++)
            {
                cout << "\n\n\tTHONG TIN NHAN VIEN XE OM CONG NGHE " << i + 1;
                driverList[i]->output();
                cout << "\nSo km chay: " << driverList[i]->getRunKilometers();
                cout << "\nTien luong: " << (size_t)driverList[i]->salaryAmount();
            }
            system("pause");
            break;
        case 0:
            exit = true;
            cout << "\n\tThoat thanh cong";
            system("pause");
            break;
        default:
            cout << "\n\tKhong xac dinh";
            system("pause");
            break;
        }

    } while (!exit);
    // ! Giải phóng vùng nhớ
    // giải phóng các đối tượng con trỏ cho danh sách nhân viên SỬA ỐNG NƯỚC
    for (int i = 0; i < n; i++)
    {
        delete (plumberList + i);
    }
    // giải phóng các đối tượng con trỏ cho danh sách nhân viên GIAO HÀNG
    for (int i = 0; i < m; i++)
    {
        delete (deliverList + i);
    }
    // giải phóng các đối tượng con trỏ cho danh sách nhân viên XE ÔM CÔNG NGHỆ
    for (int i = 0; i < l; i++)
    {
        delete (driverList + i);
    }
}

int main()
{
    // Khai báo danh sách chứa tối đa 100 đối tượng con trỏ
    // => mỗi ô nhớ là 1 con trỏ
    Plumber *plumberList[100]; // biến con trỏ đc tạo trong stack
    Deliver *deliverList[100]; // khi nào dùng toán tử new thì mới giải phóng vì lúc đó toán tử new tạo ra 100 ô nhớ trong heap
    Driver *driverList[100];

    int n = 0, m = 0, l = 0;

    menu(plumberList, deliverList, driverList, n, m, l);
    return 0;
}