/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoLab1.h"
#include "IEcoCalculatorY.h"
#include "IEcoCalculatorX.h"
void TestConstNumbers(IEcoLab1* pIEcoLab1) {
	float_t num_float=5;
	long double num_longdouble=5;
	clock_t start=0, end=0;
	double cpu_time_used=0;
	double num_double=5; 
	double epsilon=1;
	double rezi=0;
	int j=0;
	int i=0;
	for (j = 0; j <= 30; j++)
	{
		epsilon/=10;
		printf("Epsilone = %f \n", epsilon);
		j+=1;
		//////////Newton
		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtNewton(pIEcoLab1, num_double,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Newton: double - %f nanosec\n", cpu_time_used);
		start=0;
		end=0;

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtfNewton(pIEcoLab1, num_float,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Newton: float - %f nanosec\n", cpu_time_used);

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtlNewton(pIEcoLab1, num_longdouble,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Newton: long double - %f nanosec\n", cpu_time_used);
	///////HalfDivision
		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtHalfDivision(pIEcoLab1, num_double,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("CbrtHalfDivision: double - %f nanosec\n", cpu_time_used);
		start=0;
		end=0;

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtHalffDivision(pIEcoLab1, num_float,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("CbrtfHalfDivision: float - %f nanosec\n", cpu_time_used);

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtHalflDivision(pIEcoLab1, num_longdouble,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("CbrtlHalfDivision: long double - %f nanosec\n", cpu_time_used);
	}

}
void TestConstEpsilone(IEcoLab1* pIEcoLab1) {
	double number=1;
	float_t num_float=1;
	long double num_longdouble=1;
	clock_t start=0, end=0;
	double cpu_time_used=0;
	double num_double=1; 
	double epsilon=1;
	int j=0;
	int i=0;
	for (j = 0; j <= 30; j++)
	{
		number*=10;
		num_double*=10;
		num_float*=10;
		printf("Number = %f \n", number);
		j+=1;
		//////////Newton
		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtNewton(pIEcoLab1, num_double,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Newton: double - %f nanosec\n", cpu_time_used);
		start=0;
		end=0;

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtfNewton(pIEcoLab1, num_float,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Newton: float - %f nanosec\n", cpu_time_used);

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtlNewton(pIEcoLab1, num_longdouble,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Newton: long double - %Lf nanosec\n", cpu_time_used);
	////////Bisection
		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtHalfDivision(pIEcoLab1, num_double,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("CbrtHalfDivision: double - %f nanosec\n", cpu_time_used);
		start=0;
		end=0;

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtHalffDivision(pIEcoLab1, num_float,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("CbrtfHalfDivision: float - %f nanosec\n", cpu_time_used);

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pIEcoLab1->pVTbl->CbrtHalflDivision(pIEcoLab1, num_longdouble,epsilon);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("CbrtlHalfDivision: long double - %Lf nanosec\n", cpu_time_used);

		start = clock();
		for (i = 0; i <= 100000; i++) {
		pow(number, 1.0 / 3.0);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Standart: double - %f nanosec\n", cpu_time_used);
		start = clock();
		for (i = 0; i <= 100000; i++) {
		pow(number, 1.0 / 3.0);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Standart: float - %f nanosec\n", cpu_time_used);
		start = clock();
		for (i = 0; i <= 100000; i++) {
		pow(number, 1.0 / 3.0);
		}
		end = clock();
		cpu_time_used = ((double)(end - start)) ;
		printf("Standart: long double - %Lf nanosec\n", cpu_time_used);
		
	}

}
void CountAndPrint(IEcoLab1* pIEcoLab1) {
	int func=0;
	double_t rez=0;
	double_t rez2=0;
	double_t num_double=0;
	float_t num_float=0;
	long double num_longdouble=0;
	double_t epsilon=0;
	printf("Input the function 1-cbrt,2-cbrtf,3-cbrtl: \n");
	scanf("%d", &func);
	printf("Input the number: \n");
		if(func==1)
			scanf_s("%lf", &num_double);
		else if(func==2)
			scanf_s("%f", &num_float);
		else if(func==3)
			scanf_s("%Lf", &num_longdouble);
	printf("Input the epsilon: \n");
	scanf_s("%lf", &epsilon);
	if(func==1)
	{
		rez = pIEcoLab1->pVTbl->CbrtNewton(pIEcoLab1, num_double,epsilon);
		rez2 = pIEcoLab1->pVTbl->CbrtHalfDivision(pIEcoLab1, num_double,epsilon);
		printf("Newton - %f\n",rez);
		printf("HalfDivision - %f\n",rez2);
		
	}
	else if(func==2)
	{
		rez = pIEcoLab1->pVTbl->CbrtfNewton(pIEcoLab1, num_float,epsilon);
		rez2 = pIEcoLab1->pVTbl->CbrtHalffDivision(pIEcoLab1, num_float,epsilon);
		printf("HalfDivision - %f\n",rez2);
		
	}
	else if(func==3)
	{
		rez = pIEcoLab1->pVTbl->CbrtlNewton(pIEcoLab1, num_longdouble,epsilon);
		rez2 = pIEcoLab1->pVTbl->CbrtHalflDivision(pIEcoLab1, num_longdouble,epsilon);
		printf("HalfDivision - %f\n",rez2);
		
	}
	func=0;
}
/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;

	IEcoCalculatorX* pIX = 0;
    IEcoCalculatorY* pIY = 0;

	/* Дополнительные переменные */
	double_t a=10;
	double_t b=5;
	double_t x=18;
	double_t y=3;
	double_t number=0;
	double_t rez=0;
	double_t num_double=0;
	float_t num_float=0;
	long double num_longdouble=0;
	clock_t start=0, end=0;
	double cpu_time_used=0;
	double_t epsilon=0;


    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }
    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
	//TestConstNumbers(pIEcoLab1); // Тесты при number=const
	//CountAndPrint(pIEcoLab1);		//Результат извлечения корня 
	//TestConstEpsilone(pIEcoLab1);  //Тесты при epsilon=const
	//rez = pow(number, 1.0 / 3.0);
	//rez=pIEcoLab1->pVTbl->CbrtNewton(pIEcoLab1, num_double,epsilon);
	//rez=pIEcoLab1->pVTbl->CbrtHalfDivision(pIEcoLab1, num_double,epsilon);
	result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result != 0 || pIX == 0) {
        goto Release;
    }

    printf("Xfile tests:\n");
    printf("*Add - a + b = %d\n", pIX->pVTbl->Addition(pIX, a, b));
    printf("*Subtract -  a - b = %d\n", pIX->pVTbl->Subtraction(pIX, a, b));
    pIX->pVTbl->Release(pIX);


    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result != 0 || pIY == 0) {
        goto Release;
    }

    printf("Yfile tests:\n");
    printf("*Multiply - x * y = %d\n", pIY->pVTbl->Multiplication(pIY, x, y));
    printf("*Divide - x / y = %d\n", pIY->pVTbl->Division(pIY, x, y));
    pIY->pVTbl->Release(pIY);

    

    printf("\nInterface test:\n");

    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Query pIX from lab\n");
        pIX->pVTbl->Release(pIX);
    }
    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Query pIY from lab\n");
        pIY->pVTbl->Release(pIY);
    }

    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Query pIX from pIX\n");
        pIX->pVTbl->Release(pIX);
    }

    result = pIY->pVTbl->QueryInterface(pIY, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Query pIY from pIY\n");
        pIY->pVTbl->Release(pIY);
    }

    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorY, (void **) &pIY);
    if (result == 0) {
        printf("Query pIY from pIX\n");
        pIY->pVTbl->Release(pIY);
    }

    result = pIX->pVTbl->QueryInterface(pIX, &IID_IEcoCalculatorX, (void **) &pIX);
    if (result == 0) {
        printf("Query pIX from pIY\n");
        pIX->pVTbl->Release(pIX);
    }

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

