#include <iostream>
#include "vector"


enum room_type {bedroom=1, kitchen, bathroom, playroom, living_room};
enum building_type {house=1, garage, barn, bath};

struct room
{
    room_type r_type;
};

struct floor
{
    double height;
    std::vector<room> r;
};

struct building
{
    double building_area;
    building_type b_type;
    std::vector <floor> f;
};

struct sector
{
    int sector_num;
    int buildings_num;
    double sector_area;
    std::vector<building> b;
};

struct village
{
    double village_area;
    int sectors_num;
    std::vector<sector>s;
};

room roomFill(int i);
floor floorFill(int i);
building buildingFill(int building_num);
sector sectorFill(int s_num);
village villageFill(int sectors_num, double v_area);

int main() {
    std::cout << "Task 2" << std::endl;

    int S,s_num;
    std::cout << "Enter village area 'S'" << std::endl;
    std::cin >> S;
    std::cout << "Enter total sectors in this village:" << std::endl;
    std::cin >> s_num;

    village NewVasyki;

    NewVasyki = villageFill(s_num,S);

    double occupied_area=0;
    for (int i=0; i<s_num;i++)
    {
        int buildings_num = NewVasyki.s[i].buildings_num;
        for (int j=0; j<buildings_num; j++)
        {
            occupied_area+=NewVasyki.s[i].b[j].building_area;
        }
    }

    std::cout << "Occupied percentage is " << 100*(occupied_area/S) << " %" << std::endl;

    return 0;
}

room roomFill(int i)
{
    room r;
    int room_type;
    std::cout << "Enter the " << i << " room type (bedroom=1, kitchen=2, bathroom=3, playroom=4, living_room=5):" << std::endl;
    std::cin >> room_type;
    if (room_type==1) r.r_type=bedroom;
    else if (room_type==2) r.r_type=kitchen;
    else if (room_type==3) r.r_type=bathroom;
    else if (room_type==4) r.r_type=playroom;
    else if (room_type==5) r.r_type=living_room;

    return r;
}

floor floorFill(int i)
{
    floor f;
    double height;
    std::cout << "What height on the " << i << "floor?" << std::endl;
    std::cin >> height;
    f.height=height;
    int room_num;
    std::cout << "How many rooms on the " << i << "floor?" << std::endl;
    std::cin >> room_num;
    for (int j=0; j<room_num; j++)
        f.r.push_back(roomFill(j+1));

    return f;
}

building buildingFill(int building_num)
{
    building b;
    double building_area;
    int b_type;
    std::cout << "Enter " << building_num <<" building area:" << std::endl;
    std::cin >> building_area;
    b.building_area=building_area;
    std::cout << "Enter " << building_num << " building type (house=1, garage=2, barn=3, bath=4): " << std::endl;
    std::cin >> b_type;
    if (b_type==building_type::house) b.b_type = house;
    else if (b_type==building_type::garage) b.b_type = garage;
    else if (b_type==building_type::barn) b.b_type = barn;
    else if (b_type==building_type::bath) b.b_type = bath;

    if (b.b_type==house)
    {
        int floor_num;
        std::cout << "How many floors in this house?" << std::endl;
        std::cin >> floor_num;
        for (int i=0; i<floor_num; i++)
            b.f.push_back(floorFill(i+1));
    }

    return b;
}

sector sectorFill(int s_num)
{
    sector s;
    int buildings_num;
    double s_area;
    s.sector_num=s_num;
    std::cout << "How many buildings in " << s_num << " sector?" << std::endl;
    std::cin >> buildings_num;
    s.buildings_num=buildings_num;

    std::cout << "Enter " << s_num << " sector area: " << std::endl;
    std::cin >> s_area;
    s.sector_area=s_area;

    for (int i=0; i<buildings_num; i++)
    {
        s.b.push_back(buildingFill(i+1));
    }

    return s;
}

village villageFill(int sectors_num, double v_area)
{
    village v;
    v.sectors_num=sectors_num;
    v.village_area=v_area;
    for (int i=0; i<sectors_num; i++)
        v.s.push_back(sectorFill(i+1));

    return v;
}
