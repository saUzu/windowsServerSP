#include "main.h"

int wmain(int argc, char** argv)
{
	// kullanılmayan parametreler uyarı vermesin diye.
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	if (!(mainStruct = ilkAtama()))
		return EXIT_FAILURE;
	soketeBaglan();
	veriGonder();
	
	temizlik();
	return EXIT_SUCCESS;
}
