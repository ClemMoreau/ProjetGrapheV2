#ifndef GRA
#define GRA 0
#include "CSommet.h"

class CGraphe {

private:
	
	CSommet* pGRAListeSommet;

public :

	CGraphe();

	CGraphe(CGraphe& GRAGraphe);

	~CGraphe();
};

#endif //GRA

