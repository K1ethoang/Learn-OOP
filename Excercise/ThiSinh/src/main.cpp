#include "Candidates.hpp"

void menu(List &l);

int main()
{
    List l;
    menu(l);
    return 0;
}

void menu(List &l)
{
    int choose;
    bool exit = false;

    ifstream inFile;
    inFile.open("./input.txt", ios::in);
    if (!inFile)
    {
        cout << "\n\t\tLoi mo file";
        return;
    }
    else
    {
        Candidate c;
        c.toStream(inFile);
        l.push(c);
    }

    do
    {
        system("cls");
        cout << "---------------------------- MENU -----------------------------" << endl;
        cout << "\t1. Xem danh sach thi sinh" << endl;
        cout << "\t2. Them thi sinh" << endl;
        cout << "\t3. Xoa thi sinh" << endl;
        cout << "\t4. Chinh sua thi sinh" << endl;
        cout << "\t5. Thi sinh co tong diem 3 mon lon hon 15" << endl;
        cout << "\t0. Thoat chuong trinh" << endl;
        cout << "---------------------------------------------------------------";

        cout << "\n\tNhap lua chon: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            l.display();
            system("pause");
            break;
        case 2:
        {
            Candidate c;
            cout << "\n\t\tNhap thong tin thi sinh\n";
            cin >> c;
            while (l.existID(c.getIdentifyCard()))
            {
                string ID;

                cout << "\n\t(!) Da co thi sinh voi CMND nay, nhap lai: ";
                cin >> ID;
                c.setIdentifyCard(ID);
                if (!c.validId(ID))
                {
                    do
                    {
                        cout << "\n\t(!) CMND khong hop le, Nhap lai: ";
                        cin >> ID;
                        c.setIdentifyCard(ID);
                    } while (!c.validId(ID));
                }
            }
            l.push(c);
            system("pause");
            break;
        }
        case 3:
        {
            string id;
            cout << "\n\n\t\tNhap CMND thi sinh can xoa: ";
            cin >> id;
            l.deleteByID(id);
            system("pause");
            break;
        }
        case 4:
        {
            l.editCandidate();
            system("pause");
            break;
        }
        case 5:
        {
            l.searchCandidateHaveMarkOver15();
            system("pause");
            break;
        }
        case 0:
            exit = true;
            cout << "\n\t\tDa thoat chuong trinh";
            system("pause");
            break;
        default:
            cout << "\n\t\tKhong hop le!";
            system("pause");
            break;
        }
    } while (!exit);

    inFile.close();
}