#include "LibraryC.hpp"

int main()
{
    LibraryC *obj = new LibraryC;
    obj->input();
    obj->output();
    cout << "\n\n\t\tTONG TIN LAM THE: " << obj->calculatingTotalMoneyToMakeCard();

    system("pause");
    delete obj;
    return 0;
}
