#include <iostream>
#include <filesystem>

auto recursiveGetFileNamesByExtension =
        [](std::filesystem::path inPath,
           const std::string inExtension)
   {
       for(auto& p: std::filesystem::recursive_directory_iterator(inPath))
       {
           if (p.is_regular_file())
           {
               if(!p.path().extension().compare(inExtension))
                   std::cout << p.path().filename() << std::endl;
           }
       }
   };

int main() {
    std::cout << "Task 3" << std::endl;

    std::string path = "..\\test_dir";
    std::string extension = ".txt";

    recursiveGetFileNamesByExtension(path,extension);

    return 0;
}
