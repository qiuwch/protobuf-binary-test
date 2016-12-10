#include <iostream>
#include <fstream>
#include <string>
#include "unrealcv.pb.h"
#define cimg_display 0
#include "CImg.h"
using namespace std;
using namespace cimg_library;

int main()
{
    CImg<unsigned char> image("test.jpg");

    // convert an image to protobuf
    // Create a protobuf message
    printf("w %d h %d d %d c %d\n", image.width(), image.height(), image.depth(), image.spectrum());

    unrealcv::Image msg;
    msg.set_data(image.data(), image.size()); // No way to access individual pixel and I don't need this

    // Save this to disk
    fstream output("test.bin", ios::out | ios::trunc | ios::binary);
    if (!msg.SerializeToOstream(&output)) {
      cerr << "Failed to write msg to disk." << endl;
      return -1;
    }
    
    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    // for (int x = 0; x < image.width(); x++)
    // {
    //     for (int y = 0; y < image.height(); y++)
    //     {
    //         unsigned char* pixel = image.data(x, y, 0, 0);
    //         msg.set
    //     }
    // }

    // convert it back to an image
}
