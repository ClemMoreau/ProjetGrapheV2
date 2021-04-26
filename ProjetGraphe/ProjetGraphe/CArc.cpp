#include "CArc.h"

CArc::CArc()
{
	uiARDestination = 0;
}

CArc::CArc(CArc &ARCarc)
{
	uiARDestination = ARCarc.ARCLireDestination();
}

CArc::CArc(int iDestination)
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

CArc::~CArc()
{

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