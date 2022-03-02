#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<string>

using namespace std;

void mainMenu();
void adminMenu();
static int password = 123456;

class ManageMenu {

protected:
    string userName;


public:

    ManageMenu() {
        int userChoice;
        int inpass;
        system("color 9F");
        // Thay doi mau sac cua termial
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t Chon vai tro nguoi dung " << endl;
        cout << "\t\t1. Admin " << endl;
        cout << "\t\t2. Khach hang " << endl;
        cout << "Nhap lua chon : ";
        cin >> userChoice;
        if (userChoice == 1) {
            // Ham xu ly an du lieu input
            HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
            DWORD mode = 0;
            GetConsoleMode(hStdin, &mode);
            SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
            cout << "Nhap mat khau de tiep tuc : ";
            cin >> inpass;
            if (inpass == password) {
                system("CLS");
                adminMenu();// goi toi chuong trinh chinh
            }
            else {
                cout << "\nSai mat khau quay lai trang dang nhap";
                Sleep(1100);
                system("CLS");
                ManageMenu();
            }
            
        }
        else if (userChoice == 2) {
            system("CLS");
            mainMenu();
        }
        else {
            cout << "Sai cu phap !!! Vui long nhap lai " << endl;
            Sleep(1100);
            system("CLS");
            ManageMenu();

        }
    }
    ~ManageMenu() {}

};

// Lop khach hang 
class Customer {
public:
    string name, gender, address;
    int age, mobileNum,cusID;
    char all[999];
    

   

    friend istream& operator>>(istream& is, Customer& obj)
    {
        cin.ignore();
        cout << "Nhap Ho Ten: "; fflush(stdin); getline(is, obj.name);
        cout << "Nhap Gioi Tinh: "; fflush(stdin); getline(is, obj.gender);
        cout << "Nhap Dia Chi: "; fflush(stdin); getline(is, obj.address);
        cout << "Nhap Tuoi: "; is >> obj.age;
        cout << "Nhap So Dien Thoai: "; is >> obj.mobileNum;
        cout << "Thiet lap ID cho nguoi dung: "; is >> obj.cusID;
        return is;
    }

    friend ostream& operator<<(ostream& os, Customer obj)
    {
        cout << "Ho Ten: " << obj.name << endl;
        cout << "Gioi tinh " << obj.gender << endl;
        cout << "Tuoi: " << obj.age << endl;
        cout << "SDT: " << obj.mobileNum << endl;
        cout << "Dia chi: " << obj.address << endl;
        cout << "ID Khach Hang: " << obj.cusID;
        return os;
    }

};


// Lop phuong tien
class Trans
{
public:
    int transChoice;
    int distance;
    float transCost;
    static float lastTransCost;

    void transDetails() {
        cout << "Ban co hai su lua chon phuong tien di chuyen" << endl;
        cout << "1. Grab Car --- 8.000 VND/KM" << endl;
        cout << "2. Be Car --- 10.000 VND/KM" << endl;

        cout << "\nNhap phim khac de quay lai chuong trinh chinh" << endl;

        cout << "\nDe tinh toan chi phi di chuyen ..." << endl;
        cout << "Nhap loai phuong tien ban chon: ";
        cin >> transChoice;
        cout << "Nhap so km di chuyen ";
        cin >> distance;

        int hireTrans;

        if (transChoice == 1) {
            transCost = distance * 8000;
            cout << "\nChi phi di chuyen cua ban la: " << transCost << "VND cho dich vu Grab Car" << endl;
            cout << "Nhap phim 1 de xac nhan thue \n";
            cout << "Nhap phim 2 de chon phuong tien khac\n";
            cout << "Nhap lua chon cua ban : ";
            cin >> hireTrans;
            system("CLS");
            if (hireTrans == 1) {
                lastTransCost = transCost;
                cout << "\nBan da thue thanh cong Grab Car " << endl;
                cout << "Quay tro lai de lay hoa don " << endl;

            }
            else if (hireTrans == 2) {
                transDetails();
            }
            else {
                cout << "Nhap sai cu phap!!! Dang chuyen den chuong trinh chinh \n Xin vui long doi" << endl;
                Sleep(1100);
                system("CLS");
                transDetails();
            }

        }
        else if (transChoice == 2) {
            transCost = distance * 10000;
            cout << "\nChi phi di chuyen cua ban la " << transCost << " VND cho dich vu Be Car " << endl;
            cout << "Nhap 1 de xac nhan dich vu nay \n";
            cout << "Nhap 2 de chon phuong tien khac \n ";
            cout << "Nhap lua chon cua ban : ";
            cin >> hireTrans;
            system("CLS");
            if (hireTrans == 1) {
                lastTransCost = transCost;
                cout << "\n Ban da dang ky thanh cong dich vu cua Be Car!!! "<<endl;
                cout << "Quay tro lai de lay hoa don " << endl;

            }
            else if (hireTrans == 2) {
                transDetails();
            }
            else {
                cout << "Sai cu phap !!! Dang chuyen huong den chuong trinh chinh. Vui long doi " << endl;
                Sleep(1100);
                system("CLS");
                transDetails();
            }
        }
        else {
            cout << "Sai cu phap !!! Dang chuyen huong den chuong trinh chinh. Vui long doi ";
            Sleep(1100);
            system("CLS");
            mainMenu();

        }

        cout << "\nNhap 1 de chuyen huong ve chuong trinh chinh: ";
        cin >> hireTrans;
        system("CLS");
        if (hireTrans == 1) {
            mainMenu();
        }
        else {
            mainMenu();
        }
    }
};
float Trans::lastTransCost;


//Lop khach san
class Booking {
public:
    int choiceHotel;
    int packChoice;
    int gotoMenu;
    static float hotelCost;

    void hotels() {
        string hotelNo[] = { "VinPearl", "MuongThanh", "FLC" };
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". Khach San " << hotelNo[i] << endl;

        }
        cout << "\n Hien nay chung toi dang lien ket voi cac khach san tren " << endl;

        cout << "Nhan phim bat ky de quay lai chuong trinh chinh hoac\n Nhap so cua khach san ban chon ";
        cout << "\nNhap lua chon cua ban : ";
        cin >> choiceHotel;

        system("CLS");

        if (choiceHotel == 1) {
            cout << "--------- Chao mung den voi khach san Vin Pearl -------- \n";

            cout << "Khong gian rong rai, be boi sang trong, do an chat luong,... . Hay tan huong het cac dich vu cua chung toi " << endl;

            cout << "Cac goi dich vu ma chung toi dua ra cho quy khach la: \n" << endl;
            cout << " 1. Phong co view nui " << endl;
            cout << "\t Chi phi : 2000000 VND/dem" << endl;
            cout << "2. Phong co view bien " << endl;
            cout << "\t Chi phi : 3000000 VND/dem" << endl;
            cout << "3. Biet thu canh bien" << endl;
            cout << "\t Chi phi : 5000000 VND/dem" << endl;
            cout << "Nhap goi ma ban chon hoac nhap phim khac de quay lai : " ;
            cout << "Nhap lua chon cua ban : ";
            cin >> packChoice;
            if (packChoice == 1) {
                hotelCost = 2000000;
                cout << "\nBan da dat thanh cong dat phong view nui tai khach san VinPearl " << endl;
                cout << "Quay lai Menu de lay hoa don " << endl;
            }
            else if (packChoice == 2) {
                hotelCost = 3000000;
                cout << "\nBan da dat thanh cong dat phong view bien tai khach san VinPearl " << endl;
                cout << "Quay lai menu de xem hoa don " << endl;
            }
            else if (packChoice == 3) {
                hotelCost = 5000000;
                cout << "\nBan da dat thanh cong dat biet thu canh bien tai khach san VinPearl " << endl;
                cout << "Quay lai menu de xem hoa don " << endl;
            }
            else {
                cout << "Sai phim tat.. Dang quay lai menu chinh... \nPlease Wait!..." << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nNhap phim 1 de quay lai Menu ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1) {
                mainMenu();
            }
            else {
                mainMenu();
            }
        }
        else if (choiceHotel == 2) {
            cout << "--------- Chao mung den voi khach san Muong Thanh -------- \n";

            cout << "Khach san 4 sao | Do an tieu chuan quoc te | Day du tien nghi " << endl;

            cout << "Cac goi dich vu ma chung toi dua ra cho quy khach la: \n" << endl;
            cout << " 1. Phong co view nui " << endl;
            cout << "\t Chi phi : 1000000 VND/dem" << endl;
            cout << "2. Phong co view song " << endl;
            cout << "\t Chi phi : 2000000 VND/dem" << endl;
            cout << "3. Biet thu canh song" << endl;
            cout << "\t Chi phi : 4200000 VND/dem" << endl;
            cout << "Nhap goi ma ban chon hoac nhap phim bat ky de quay lai" << endl;
            cout << "Nhap lua chon cua ban : ";
            cin >> packChoice;
            if (packChoice == 1) {
                hotelCost = 2000000;
                cout << "\nBan da dat thanh cong dat phong view nui tai khach san Muong Thanh " << endl;
                cout << "Quay lai Menu de lay hoa don " << endl;
            }
            else if (packChoice == 2) {
                hotelCost = 3000000;
                cout << "\nBan da dat thanh cong dat phong view song tai khach san Muong Thanh " << endl;
                cout << "Quay lai menu de xem hoa don " << endl;
            }
            else if (packChoice == 3) {
                hotelCost = 5000000;
                cout << "\nBan da dat thanh cong dat biet thu canh song tai khach san Muong Thanh " << endl;
                cout << "Quay lai menu de xem hoa don " << endl;
            }
            else {
                cout << "Sai phim tat.. Dang quay lai menu chinh... \nPlease Wait!..." << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nNhap phim 1 de quay lai Menu ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1) {
                mainMenu();
            }
            else {
                mainMenu();
            }
        }
        else if (choiceHotel == 3) {
            cout << "--------- Chao mung den voi khach san FLC -------- \n";

            cout << "San golf rong | Cong vien ho boi giai tri | Khung canh hoang so " << endl;

            cout << "Cac goi dich vu ma chung toi dua ra cho quy khach la: \n" << endl;
            cout << " 1. Phong co view nui " << endl;
            cout << "\t Chi phi : 1700000 VND/dem" << endl;
            cout << "2. Phong co view bien " << endl;
            cout << "\t Chi phi : 3300000 VND/dem" << endl;
            cout << "3. Biet thu tren nui" << endl;
            cout << "\t Chi phi : 5600000 VND/dem" << endl;
            cout << "Nhap goi ma ban chon hoac nhap phim bat ky de quay lai" << endl;
            cout << "Nhap lua chon cua ban : ";
            cin >> packChoice;
            if (packChoice == 1) {
                hotelCost = 2000000;
                cout << "\nBan da dat thanh cong dat phong view nui tai khach san FLC " << endl;
                cout << "Quay lai Menu de lay hoa don " << endl;
            }
            else if (packChoice == 2) {
                hotelCost = 3000000;
                cout << "\nBan da dat thanh cong dat phong view bien tai khach san FLC " << endl;
                cout << "Quay lai menu de xem hoa don " << endl;
            }
            else if (packChoice == 3) {
                hotelCost = 5000000;
                cout << "\nBan da dat thanh cong dat biet thu tren nui tai khach san FLC " << endl;
                cout << "Quay lai menu de xem hoa don " << endl;
            }
            else {
                cout << "Sai phim tat.. Dang quay lai menu chinh... \nPlease Wait!..." << endl;
                Sleep(1100);
                system("CLS");
                hotels();

            }

            cout << "\nNhap phim 1 de quay lai menu chinh : ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1) {
                mainMenu();
            }
            else {
                mainMenu();
            }
        }
    }
};

float Booking::hotelCost;


// Lop thanh toan
class Chargers : public Booking, Trans, Customer
{

public:
    void printBill() {
        ofstream outf("receipt.txt");
        {
            outf << "----------- Dich vu du lich P&T ----------" << endl;
            outf << "---------------- HOA DON -----------------" << endl;
            outf << "__________________________________________" << endl;

            outf << "ID Khach Hang: " << Customer::cusID << endl;

            outf << "CHI TIET \t\t Tong Cong  " << endl;

            outf << "Khach san:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Di Chuyen:\t\t " << fixed << setprecision(2) << Trans::lastTransCost << endl;

            outf << "___________________________________________" << endl;
            outf << "Tong chi phi : \t\t " << fixed << setprecision(2) << Booking::hotelCost + Trans::lastTransCost << endl;
            outf << "___________________________________________" << endl;
            outf << "Cam on ban da su dung dich vu cua chung toi" << endl;

        }
        outf.close();
    }
    void showBill() {
        ifstream inf("receipt.txt");
        {
            if (!inf) {
                cout << "Loi File !!!" << endl;

            }
            while (!(inf.eof())) {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

Customer cus_list[10];
int i = -1;


// Menu cua admin
void adminMenu() {
    int mainChoice;
    int inChoice;
    int gotoMenu;
    int inpass;
    cout << "\t\t      * Dich vu du lich P&T *\n" << endl;
    cout << "-------------------------Admin Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;

    cout << "\t|\t1. Quan ly khach hang\t\t|" << endl;
    cout << "\t|\t2. Xem cac dich vu ket noi \t|" << endl;
    cout << "\t|\t3. Quay lai \t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nNhap lua chon: ";
    cin >> mainChoice;

    system("CLS");

  
    Trans trans;
    Booking hotel;
    Chargers chargers;


    if (mainChoice == 1) {

        cout << "------Khach hang------\n" << endl;
        cout << "1. Nhap khach hang moi " << endl;
        cout << "2. Xem thong tin khach hang cu" << endl;

        cout << "\nNhap lua chon: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1) {
            i++;
            cin >> cus_list[i];
                
        }
        else if (inChoice == 2) {
            cout << "----- Danh sach cac khach hang -------" << endl;
            for (int j = 0; j <= i; j++) {
                cout << j + 1 << "." << endl;
                cout << cus_list[j];
                cout << endl;
            }
        }
        else {
            cout << "Loi cu phap, dang quay lai menu \nPlease Wait!!!" << endl;
            Sleep(1100);
            system("CLS");
            adminMenu();
        }
        cout << "Nhap phim 1 de quay lai : ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1) {
            adminMenu();
        }
        else {
            adminMenu();
        }
    }
        
    else if (mainChoice == 2) {
        cout << "-------- Thong tin cac dich vu dang hop tac -----------" << endl;
        cout << "\n\nCac dich vu xe :" << endl;
        cout << "- Grab Bike " << endl;
        cout << "- Be Bike " << endl;
        cout << "\n\nCac dich vu khach san :" << endl;
        cout << "- Vin Pearl " << endl;
        cout << "- Muong Thanh " << endl;
        cout << "- FLC " << endl;
        cout << "\n\nNhap phim 1 de quay lai : ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1) {
            adminMenu();
        }
        else {
            adminMenu();
        }
    }
    else if (mainChoice == 3) {
        cout << "Quay lai trang dang nhap... " << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
}
int logined = 0;


// Menu cua khach hang 
void mainMenu() {
    int mainChoice;
    int inChoice;
    int gotoMenu;
    int id_login;
    int flag = 0;
    int inpass;
 
    while (logined == 0) {
        cout << "Vui long nhap id nguoi dung do admin cung cap: ";
        cin >> id_login;
        for (int j = 0; j < 10; j++)
        {
            if (id_login == cus_list[j].cusID) {
                logined = 1;
                flag = j;
                break;
            }
           
        }
        
    }
    
    system("CLS");
    cout << "\t\t      * Dich vu du lich P&T *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;

    cout << "\t|\t1. Thong tin khach hang\t\t|" << endl;
    cout << "\t|\t2. Dat phuong tien di chuyen\t|" << endl;
    cout << "\t|\t3. Dat phong khach san\t\t|" << endl;
    cout << "\t|\t4. Chi phi va Hoa don\t\t|" << endl;
    cout << "\t|\t5. Quay lai\t\t\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nNhap lua chon: ";
    cin >> mainChoice;

    system("CLS");


    Trans trans;
    Booking hotel;
    Chargers chargers;



    if (mainChoice == 1) {
        cout << cus_list[flag];
        cout << "\n Nhap phim 1 de quay lai Mainmenu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1) {
            mainMenu();
        }
        else {
            mainMenu();
        }
    }
    else if (mainChoice == 2) {
        trans.transDetails();
    }
    else if (mainChoice == 3) {
        cout << "--> Dat mot khach san ung y voi ban nhat <--\n" << endl;
        hotel.hotels();
    }
    else if (mainChoice == 4) {
        cout << "-->Chi phi va Hoa don <--\n" << endl;
        chargers.printBill();
        cout << "Hoa don cua ban da co san, ban co the tai ve va in ra.\n" << endl;
        cout << "De quay tro ve nhap phim 1 hoac enter :";
        cin >> gotoMenu;
        if (gotoMenu == 1) {
            system("CLS");
            chargers.showBill();
            cout << "Nhap phim 1 de quay lai  ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1) {
                mainMenu();
            }
            else {
                mainMenu();
            }
        }
        else {
            system("CLS");
            mainMenu();
        }
    }
    else if (mainChoice == 5) {
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        logined = 0;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else {
        cout << "Loi cu phap! Dang quay lai menu \nPlease Wait!!!!" << endl;
        Sleep(1100);
        system("CLS");
        mainMenu();
    }
}

int main()
{   // Ham thay doi co chu 
    HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
    font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(cons, 0, font);
    font->dwFontSize.X = 15;
    font->dwFontSize.Y = 30;
    font->FontWeight = 22;
    font->FontFamily = FF_DECORATIVE;
    SetCurrentConsoleFontEx(cons, 0, font);
    cout << "Ung dung dat dich vu du lich  !!" << endl;
    ManageMenu();
    return 0;
}


