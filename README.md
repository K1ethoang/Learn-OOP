- [1. Các tính chất của OOP](#1-các-tính-chất-của-oop)
  - [1.1. Tính đóng gói (Encapsulation)](#11-tính-đóng-gói-encapsulation)
  - [1.2. Tính trừu tượng (Abstraction)](#12-tính-trừu-tượng-abstraction)
  - [1.3. Tính kế thừa (Inheritance)](#13-tính-kế-thừa-inheritance)
  - [1.4. Tính đa hình (Polymorphism)](#14-tính-đa-hình-polymorphism)
    - [1.4.1. Phương thức ảo (virtual)](#141-phương-thức-ảo-virtual)
    - [1.4.2. Phương thức thuần ảo (Pure Virtual)](#142-phương-thức-thuần-ảo-pure-virtual)
    - [1.4.3. Khi nào dùng phương thức ảo - thuần ảo](#143-khi-nào-dùng-phương-thức-ảo---thuần-ảo)
- [2. Bonus](#2-bonus)
  - [2.1. this keyword](#21-this-keyword)

# 1. Các tính chất của OOP
## 1.1. Tính đóng gói (Encapsulation)

- access modifier:
    + **private**: Thành phần có thuộc tính này sẽ chỉ được truy cập từ bên trong lớp cơ sở.
Bên ngoài lớp hay trong lớp dẫn xuất sẽ không thể truy cập được.
    + **public**: Không hạn chế. Thành phần có thuộc tính này có thể được truy cập ở bất kì vị trí nào.
    + **protected**: Mở rộng hơn private một chút. Thành phần có thuộc tính này sẽ có thể truy cập ở trong nội bộ lớp 
và trong lớp dẫn xuất ( lớp dẫn xuất sẽ được trình bày trong bài Tính Kế Thừa ) chỉ có thể truy cập bởi lớp dẫn xuất

- Nếu ko chỉ rõ access modifier -> mặc định là public

<details>
<summary> Code </summary>

```cpp

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

```

</details>


## 1.2. Tính trừu tượng (Abstraction)

## 1.3. Tính kế thừa (Inheritance)

<details>
<summary> Cú pháp </summary>

```
class <tên class con> : < access modifier> <tên class cha>
```

```cpp
class child : public parent
```
- ***Nếu không chỉ rõ access modifier thì mặc định là private***

</details>

- các phạm vi kế thừa:
  - **public**: Nếu kế thừa ở dạng này, sau khi kế thừa, tất cả các thành viên *public lớp cha sẽ public ở lớp con, protected ở lớp cha vẫn sẽ là protected ở lớp con*.

  - **protected**: Nếu dùng protected thì sau khi kế thừa, tất cả các thành viên *public lớp cha sẽ trở thành protected tại lớp con*.

  - **private**: Trường hợp ta sử dụng private, thì sau khi kế thừa, tất cả các thành viên *public và protected ở lớp cha sẽ thành private tại lớp con*.

- có 2 loại kế thừa:
  - **Đơn kế Thừa**  
  - **Đa kế thừa**: chỉ có tở C++ bên Java & C# không có 


## 1.4. Tính đa hình (Polymorphism)
- Từ khoá **`virtual`**: gọi đến những hàm được **overriding** ở lớp dẫn xuất
- **Overriding** (ghi đè): định nghĩa lại 1 phương thức ở lớp cơ sở
- **Overloading** (nạp chồng): các phương thức có tên giồng nhau nhưng khác số lượng tham số hoặc kiểu dữ liệu tham số


### 1.4.1. Phương thức ảo (virtual)
- Những phương thức ở lớp cha được khai báo với từ khoá **`virtual`** - thì các lớp con kế
thừa từ nó cũng sẽ cài đặt lại các phương thức trùng tên của lớp cha để cho phép các Phương
thức của lớp con có thể nạp chồng lại được (overriding)
- Nếu như các phương thức của lớp cha không có từ khoá **`virtual`** thì khi chúng ta "new" ra 
1 đối tượng con bất kì thì nó sẽ mặc định chạy về phương thức trùng tên ở lớp cha

<details>
<summary> TÁC DỤNG CỦA TỪ KHOÁ VIRTUAL </summary>

- Nếu như các phương thức của lớp cha có khai báo từ khoá virtual thì khi new ra 1 đối tượng
con nào đó bất kì thì khi đó nó sẽ chạy vào phương thức trùng tên của lớp con đó - nó cho
chúng ta gọi lại phương thức trùng tên của lớp con

</details>

<details>
<summary> CÚ PHÁP KHAI BÁO PHƯƠNG THỨC ẢO </summary>

```
virtual<kiểu dữ liệu><tên phương thức>(các tham số truyền vào nếu có);
```

```cpp
virtual void alert() // phương thức ảo
    {
        cout << "Hello word" << endl;
    }
```

</details>

### 1.4.2. Phương thức thuần ảo (Pure Virtual)
- Những phương thức sẽ được khai báo ở lớp cha - còn việc định nghĩa sẽ do các lớp con kế thừa từ nó đảm nhận - bắt buộc

<details>
<summary> CÚ PHÁP KHAI BÁO PHƯƠNG THỨC ẢO </summary>

```
virtual<kiểu dữ liệu><tên phương thức>(các tham số truyền vào nếu có)=0;
```

```cpp
virtual void calculate() = 0; // phương thức thuần ảo
```

</details>

<details>
<summary> LƯU Ý </summary>

- Nếu ở lớp cha có các khai báo phương thức thuần ảo - thì qui tắc các lớp con nào mà kế thừa lại từ lớp cha - thì các lớp con kế thừa từ lớp cha đó bắt buộc phải đi định nghĩa lại phương thưc thuần ảo của lớp cha đó - nếu lớp con mà không định nghĩa ==> `sẽ bị lỗi`

</details>


### 1.4.3. Khi nào dùng phương thức ảo - thuần ảo

<details>
<summary> ẢO </summary>

- Dùng khi ở lớp cha **có** thông tin gì để xử lí  

</details>

<details>
<summary> THUẦN ẢO </summary>

- Dùng khi ở lớp cha **không có** thông tin để xử lí

</details>
TUỲ CƠ ỨNG BIẾN

`" BIẾN CÁI PHƯƠNG THỨC THUẦN ẢO -> PHƯƠNG THỨC ẢO "`

# 2. Bonus

## 2.1. this keyword
<details>
<summary> Open </summary>

- Dùng this là để chương trình hiểu là ta đang gọi đến member của object chứ không phải là biến thamn số của hàm:
    - Nếu biến đó không tôn tại trong phương thức mà nó lại trùng với tên thuộc tính thì mặc nhiên nó sẽ hiểu đó là thuộc tính.
    - Nếu biến đó có khai báo trong phương thức thì ta sẽ hiểu đó là biến bình thường, không phải là thuộc tính.
    - 
</details>
