#include "StdAfx.h"
#include "exampleController.h"

CExampleController* CExampleController::m_pContoller=nullptr;
CExampleController::CExampleController(void)
{
}

CExampleController::CExampleController( const CExampleController& )
{

}


CExampleController::~CExampleController(void)
{
	
}

CExampleController& CExampleController::operator=( const CExampleController& )
{
	return *this;
}

CExampleController* CExampleController::GetInstance()
{
	if (nullptr==m_pContoller)
	{
		m_pContoller=new CExampleController();
	}
	return m_pContoller;
}

void CExampleController::ReleaseInstance()
{
	if (m_pContoller!=nullptr)
	{
		delete m_pContoller;
		m_pContoller=nullptr;
	}
}
