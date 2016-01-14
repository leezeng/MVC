#pragma once
class CExampleController
{
private:
	CExampleController(void);
	~CExampleController(void);
	CExampleController(const CExampleController&);
	CExampleController& operator=(const CExampleController&);
public:
	static CExampleController* GetInstance();
	static void ReleaseInstance();
	static CExampleController* m_pContoller;
};

