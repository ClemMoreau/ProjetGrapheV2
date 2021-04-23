#ifndef ARC
#define ARC 0

class CArc
{
private:
	unsigned int uiARDestination;

public:
	CArc();

	CArc(CArc &Carc);

	~CArc();

	unsigned int ARCLireDestination();

	void ARcModifierDestination(int iDestination);
};

#endif //ARC