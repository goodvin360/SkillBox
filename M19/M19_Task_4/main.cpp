#include <iostream>
#include "fstream"

using namespace std;

int main() {
    cout << "Task 4" << endl;
    string path;
    cout << "Enter path of the file (for example '..\\test1.png' or 'C:\\Users\\User\\CLionProjects\\SkillBox\\M19\\M19_Task_4\\test2.png'):" << endl;
    cin >> path;
//    string path = "..\\test.png";

    bool ch1, ch2;
    char tmp[4];
    auto p = path.rfind(".png");
    if(p!=-1) ch1=true;

    fstream f(path, ios::in|ios::binary);
    if(!f.is_open()){
        cerr << "File open error!" << endl;
        exit(1);
    }
    for(int i=0; i<4; i++){
        f.read(&tmp[i], sizeof(char));
    }
    f.close();
    if(tmp[0]==-119&&tmp[1]=='P'&&tmp[2]=='N'&&tmp[3]=='G') ch2=true;

    if(ch1==true&&ch2==true){
        cout << "It's PNG-file";
    } else{
        cout << "It's not PNG-file";
    }
    return 0;
}
