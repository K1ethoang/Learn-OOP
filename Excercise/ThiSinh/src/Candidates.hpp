#pragma once

#include "Candidate.hpp"
#include <fstream>

class Node
{
public:
    Candidate data;
    Node *pNext;

    Node() {}

    Node(Candidate data)
    {
        this->data = data;
        pNext = NULL;
    }
};

class List
{
private:
    Node *pHead;
    Node *pTail;
    int size;

private:
    void delHead();
    void delTail();

public:
    List();
    ~List();
    Node *getHead();
    Node *getTail();
    int getSize();
    void setHead(Node *pNew);
    void setTail(Node *pNew);
    void setSize(int newSize);
    void display();
    void push(Candidate val);
    void deleteByID(string ID);
    void editCandidate();
    void sortByMark();
    void searchCandidateHaveMarkOver15();
    bool existID(const string &ID);
};

List::List()
{
    pHead = pTail = NULL;
    size = 0;
}

List::~List() // giải phóng bộ nhớ của danh sách
{
    Node *t = NULL;
    while (pHead != NULL)
    {
        t = pHead;
        pHead = pHead->pNext;
        delete t;
    }
}

Node *List::getHead()
{
    return this->pHead;
}

Node *List::getTail()
{
    return this->pTail;
}

int List::getSize()
{
    return this->size;
}

void List::setHead(Node *pNew)
{
    this->pHead = pNew;
}

void List::setTail(Node *pNew)
{
    this->pTail = pNew;
}

void List::setSize(int newSize)
{
    this->size = newSize;
}

void List::display()
{
    if (pHead == NULL)
    {
        cout << "\n\n\t\tDanh sanh rong";
    }
    else
    {
        int i = 1;
        for (Node *t = pHead; t != NULL; t = t->pNext)
        {
            cout << "\n\n\t\tThi sinh " << i++ << endl;
            cout << t->data;
        }
    }
    cout << "\n\n\tSo thi sinh hien co: " << size;
}

void List::push(Candidate val) // thêm vào cuối
{
    bool check = false;
    Node *p = new Node(val);
    if (pHead == NULL) // danh sách rỗng
    {
        pHead = pTail = p;
        check = true;
        cout << "\n\n\t\tThong tin thi sinh vua them" << endl;
        cout << p->data;
    }
    else
    {
        pTail->pNext = p;
        pTail = p;
        check = true;
        cout << "\n\n\t\tThong tin thi sinh vua them" << endl;
        cout << p->data;
    }
    if (!check)
    {
        cout << "\n\n\t\tThem that bai";
    }
    size++;
}

void List::delHead() // hàm phụ: xoá node đầu
{
    if (pHead == NULL) // rỗng
    {
        return;
    }
    else
    {
        Node *t = pHead;
        pHead = pHead->pNext;
        delete t;
        size--;
    }
}

void List::delTail() // hàm phụ: xoá node cuối
{
    if (pHead == NULL) // rỗng
    {
        return;
    }
    else if (pHead->pNext == NULL) // 1 phần tử
    {
        delHead();
    }
    else // duyệt
    {
        for (Node *t = pHead; t != NULL; t = t->pNext)
        {
            if (t->pNext == pTail)
            {
                delete pTail;
                t->pNext = NULL;
                pTail = t; // cập nhật lại pTail
                size--;
                return;
            }
        }
    }
}

void List::deleteByID(string ID) // xoá theo số báo danh
{
    bool check = false;
    if (pHead == NULL)
    {
        cout << "\n\n\t\tDanh sach rong";
        return;
    }
    else if (pHead->data.getIdentifyCard().compare(ID) == 0)
    {
        delHead();
        check = true;
        cout << "\n\n\t\tXoa thanh cong";
    }
    else if (pTail->data.getIdentifyCard().compare(ID) == 0)
    {
        delTail();
        check = true;
        cout << "\n\n\t\tXoa thanh cong";
    }
    else
    {
        Node *g = new Node();
        for (Node *t = pHead; t != NULL; t = t->pNext)
        {
            if (t->data.getIdentifyCard().compare(ID) == 0)
            {
                g->pNext = t->pNext;
                delete t;
                size--;
                check = true;
                cout << "\n\n\t\tXoa thanh cong";
                return;
            }
            g = t; // node trước node cần xoá
        }
    }
    if (!check)
        cout << "\n\n\t\tKhong co thi sinh nay";
}

void List::editCandidate()
{
    string id;
    bool check = false;
    cout << "\nNhap CMND thi sinh can chinh sua: ";
    cin >> id;

    for (Node *t = pHead; t != NULL; t = t->pNext)
    {
        if (t->data.getIdentifyCard().compare(id) == 0)
        {
            cout << "\n\n\t\tNhap thong tin can chinh sua" << endl;
            cin >> t->data;
            check = true;
            cout << "\n\n\t\tThong tin vua chinh sua" << endl;
            cout << t->data;
            return;
        }
    }
    if (!check)
        cout << "\n\n\t\tKhong co thi sinh nay";
}

void swap(Candidate &x, Candidate &y) // hàm ngoài
{
    Candidate t = x;
    x = y;
    y = t;
}

void List::sortByMark() // tăng dần
{
    // Selection sort

    for (Node *t = pHead; t != pTail; t = t->pNext)
    {
        Node *minMarkPos = t;
        for (Node *g = t->pNext; g != NULL; g = g->pNext)
        {
            if (minMarkPos->data.sumOfMark() > g->data.sumOfMark())
            {
                minMarkPos = g;
            }
        }
        if (minMarkPos != t)
        {
            swap(t->data, minMarkPos->data);
        }
    }
}

void List::searchCandidateHaveMarkOver15()
{
    int i = 1;
    bool check = false;
    for (Node *t = pHead; t != NULL; t = t->pNext)
    {
        if (t->data.sumOfMark() > 15)
        {
            cout << "\n\n\t\tThi sinh thu " << i++ << endl;
            cout << t->data;
            check = true;
        }
    }

    if (!check)
        cout << "\n\n\t\tKhong co thi sinh nao";
}

bool List::existID(const string &ID)
{
    for (Node *t = pHead; t != NULL; t = t->pNext)
    {
        if (t->data.getIdentifyCard().compare(ID) == 0)
        {
            return true;
        }
    }
    return false;
}