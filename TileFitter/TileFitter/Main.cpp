#include "Header.h"

int main() {
	io::CSVReader<2> in("Test.csv");
	in.read_header(io::ignore_extra_column, "width", "height");
	int width; int height;
	while (in.read_row(width, height)) {
		printf("width: %i , height: %i \n",width,height);
	}
}