#include <iostream>
#include "fstream"


int main() {

    char tmp; int n=0, com=1;
    std::string path;
    std::cout << "Enter path of the file (for example '..\\words.txt' or 'C:\\Users\\User\\CLionProjects\\SkillBox\\M19\\M19_Task_2\\words.txt'):" << std::endl;
    std::cin >> path;
//    string path = "..\\words.txt";
    std::fstream f(path, std::ios::in|std::ios::binary);
    if(!f.is_open()){
        std::cerr << "File open error!" << std::endl;
        exit(1);
    }
    while (f.read(&tmp, sizeof(char))&&!f.eof()) {
        std::cout << tmp;
        n += f.gcount();
    }
    std::cout <<std::endl<<std::endl << "File has been read! Size: "<<n<<" bytes"<<std::endl;
    f.close();


    return 0;

}
