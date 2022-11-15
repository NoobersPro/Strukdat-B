#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
    protected:
        string MHSname;

    public:
        Mahasiswa(string mhs) {
            MHSname = mhs;
        }

        void getName(){
            cout << "MHS name is : "<< MHSname << endl;
        }
};

int main(){
    Mahasiswa mhs1("Nas");
    mhs1.getName();
}
