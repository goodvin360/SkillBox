#include <iostream>

using namespace std;

string caesar_encrypt(string str, int key)
{
    for (int i=0; i<str.length(); i++) {
        if (str[i]>='A'&& str[i]<='Z')
        {
            int num = str[i]-'A';
            key>=0 ? num+=key : num+=(26+key);
            str[i] = (char)(num%26+(int)'A');
        }
        else if (str[i]>='a'&&str[i]<='z')
        {
            int num = str[i]-'a';
            key>=0 ? num+=key : num+=(26+key);
            str[i] = (char)(num%26+(int)'a');
        }
        else str[i]=str[i];
    }
    return str;
}

string caesar_decrypt(string str, int key)
{
    return (caesar_encrypt(str,-key));
}

int main() {
    std::cout << "Caesar Encrypt" << std::endl;
    string str, str_encrypted, str_decrypted;
    int key;
    cout << "Enter text to encrypt: " << endl;
    getline(cin, str);
    cout << "Enter encrypt key: " << endl;
    cin >> key;
    str_encrypted=caesar_encrypt(str,key);
    str_decrypted=caesar_decrypt(str_encrypted,key);
    cout << "encrypted text: " << endl << str_encrypted << endl;
    cout << endl;
    cout << "decrypted text: " << endl << str_decrypted << endl;
    return 0;
}