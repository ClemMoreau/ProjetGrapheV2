#ifndef  SOM
#define SOM 0

#include "CArc.h"

class CSommet {

private:

	unsigned int uiSOMNumero;

	CArc** ppARCSOMArcArrivant;

	CArc** ppARCSOMArcSortant;

public:

	CSommet();

	CSommet(CSommet& SOMSommet);

	~CSommet();


};

#endif // SOM