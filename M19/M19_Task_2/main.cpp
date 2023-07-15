#include <iostream>
#include "fstream"

using namespace std;

int main() {

    char tmp; int n=0, com=1;
    string path;
    cout << "Enter path of the file (for example '..\\words.txt' or 'C:\\Users\\User\\CLionProjects\\SkillBox\\M19\\M19_Task_2\\words.txt'):" << endl;
    cin >> path;
//    string path = "..\\words.txt";
    fstream f(path, ios::in|ios::binary);
    if(!f.is_open()){
        cerr << "File open error!" << endl;
        exit(1);
    }
    while (f.read(&tmp, sizeof(char))&&!f.eof()) {
        cout << tmp;
        n += f.gcount();
    }
    cout <<endl<<endl << "File has been read! Size: "<<n<<" bytes"<<endl;
    f.close();


    return 0;

}
