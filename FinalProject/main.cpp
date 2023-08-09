#include <iostream>
#include "JsonFill.h"
#include "ConverterJson.h"
#include "InvertedIndex.h"
#include "SearchServer.h"
#include "thread"


void showDocs()
{
    std::cout << std::endl;
    for (int i=0; i<3; i++)
    {
        std::stringstream path;
        path << "../resources/file00" << i+1 << ".txt";
        std::ifstream file(path.str());
        while (!file.eof()) {
            std::string tmp{};
            file >> tmp;
            std::cout << tmp << " ";

        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

void createJsons()
{
    JsonFill fileExample;
    fileExample.fillFile("config");
    fileExample.printFile("config", "../config.json");
    fileExample.fillFile("request");
    fileExample.printFile("request", "../request.json");
}

int main() {

//    createJsons();
//    showDocs();

    ConverterJson conv;
    conv.GetResponseLimit();
    conv.GetRequests();
    InvertedIndex inv(conv);
    inv.UpdateDocumentBase(conv.GetTextDocuments());
    SearchServer serv(inv, conv);
    conv.putAnswers(serv.searchFoo(conv.GetRequestsData()));

    std::cout << "Program finished. Good luck :) " << std::endl;
    return 0;
}
