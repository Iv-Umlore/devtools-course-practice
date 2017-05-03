#include "../gtest/gtest.h"
#include "../TPolinoms.h"

TEST(TRootLink, SetNextLink)		
{
	TDatLink sec(NULL);
	PTDatLink pdv1 = &sec;
	TDatLink first(NULL);
	first.SetNextLink(pdv1);
	EXPECT_EQ(&sec, first.GetNextLink());
}

TEST(TRootLink, GetNextLink)		
{
	TDatLink sec(NULL);
	PTDatLink pdv1 = &sec;
	TDatLink first(NULL, pdv1);
	EXPECT_EQ(&sec, first.GetNextLink());
}

TEST(TRootLink, InsNextLink)		
{
	TDatLink sec(NULL);
	PTDatLink pdv1 = &sec;
	TDatLink first(NULL,pdv1);
	TDatLink third(NULL);		
	first.InsNextLink(&third);
	EXPECT_EQ(&third, first.GetNextLink());
}


TEST(TDatLink, create_DatLink )		
{
	TDatLink sec(NULL);
	EXPECT_NO_FATAL_FAILURE(TDatLink first(NULL, &sec));
}

TEST(TDatLink, SetDatLalue)		
{
	PTDatValue pdv=NULL;
	TDatLink dl(NULL, NULL);
	EXPECT_NO_FATAL_FAILURE(dl.SetDatValue(pdv));
}

TEST(TDatLink, GetDatValue)		
{
	PTDatValue pdv=NULL;
	TDatLink dl;
	dl.SetDatValue(pdv);
	EXPECT_EQ(dl.GetDatValue(), pdv);
}

TEST(TDatLink, GetNextDatLink)	
{
	TDatLink dl1;
	TDatLink dl2;
	dl1.SetNextLink(&dl2);
	EXPECT_EQ(&dl2, dl1.GetNextDatLink());
}

