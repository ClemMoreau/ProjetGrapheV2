#include "CArc.h"

CArc::CArc()
{
	ARCModifierDestination(0);
}

CArc::CArc(CArc &ARCarc)
{
	ARCModifierDestination(ARCarc.ARCLireDestination());
}

CArc::CArc(int iDestination)
{
	if (iDestination < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Numero sommet negatif !");
		throw(EXCLevee);
	}
	ARCModifierDestination(iDestination);
}

CArc::~CArc()
{
	ARCModifierDestination(0);
}

unsigned int CArc::ARCLireDestination()
{
	return uiARDestination;
}

void CArc::ARCModifierDestination(int iDestination)
{
	if (iDestination < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(destination_negatif);
		EXCLevee.EXCmodifier_message("Destination negative !");
		throw(EXCLevee);
	}
	uiARDestination = iDestination;
}