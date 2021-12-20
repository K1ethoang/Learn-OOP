#include "LibraryC.hpp"

int main()
{
    LibraryC *obj = new LibraryC();
    obj->input();
    obj->output();
    cout << "\n\n\t\tTONG TIEN LAM THE: " << obj->calculatingTotalMoneyToMakeCard();

    delete obj;
    system("pause");
    return 0;
}
