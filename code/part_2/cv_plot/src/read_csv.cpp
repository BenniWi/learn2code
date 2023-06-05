#include <rapidcsv.h>

#include <iostream>
#include <string>
#include <vector>

auto main() -> int
{
    rapidcsv::Document doc(std::string(RESOURCEPATH) + "/colrowhdr.csv", rapidcsv::LabelParams(0, 0));

    std::vector<float> col = doc.GetColumn<float>("Close");
    std::cout << "Read " << col.size() << " values." << std::endl;

    auto volume = doc.GetCell<int64_t>("Volume", "2017-02-22");
    std::cout << "Volume " << volume << " on 2017-02-22." << std::endl;

    return 0;
}