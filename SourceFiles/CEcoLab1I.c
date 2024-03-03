/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CEcoLab1.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1_QueryInterface(/* in */ struct IEcoLab1* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
	else if ( IsEqualUGUID(riid, &IID_IEcoLab1) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_AddRef(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1_Release(/* in */ struct IEcoLab1* me) {
    CEcoLab1* pCMe = (CEcoLab1*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1((IEcoLab1*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
double fabsi(double x) {
    return (x < 0) ? -x : x;
}
double_t ECOCALLMETHOD CEcoLab1_CbrtNewton(/* in */ struct IEcoLab1* me, /* in */ double_t number) {
	double epsilon = 0.00000000000000000000000000000000000000000000000001;
    double x = number; // начальное приближение

    while (1) {
        double prev_x = x;
        x = (2 * x + number / (x * x)) / 3; // формула Ньютона для кубического корня

        // Проверяем, достигнута ли требуемая точность
        if (fabsi(x - prev_x) < epsilon) {
            break;
        }
    }

    return x;
}
float_t ECOCALLMETHOD CEcoLab1_CbrtfNewton(/* in */ struct IEcoLab1* me, /* in */ float_t number) {
	double epsilon = 0.0001;
   /* if (me == NULL || epsilon == NULL) {
        return -1;
	}*/

    double x0 = number; // Начальное приближение
    double x1 = (2 * x0 + number / (x0 * x0)) / 3; // Формула Ньютона

    // Итеративное вычисление
    while (fabsi(x1 - x0) >= epsilon) {
        x0 = x1;
        x1 = (2 * x0 + number / (x0 * x0)) / 3;
    }

    return x1;
}
long double ECOCALLMETHOD CEcoLab1_CbrtlNewton(/* in */ struct IEcoLab1* me, /* in */ long double number) {
	double epsilon = 0.0001;
   /* if (me == NULL || epsilon == NULL) {
        return -1;
	}*/

    double x0 = number; // Начальное приближение
    double x1 = (2 * x0 + number / (x0 * x0)) / 3; // Формула Ньютона

    // Итеративное вычисление
    while (fabsi(x1 - x0) >= epsilon) {
        x0 = x1;
        x1 = (2 * x0 + number / (x0 * x0)) / 3;
    }

    return x1;
}
double_t ECOCALLMETHOD CEcoLab1_CbrtHalfDivision(/* in */ struct IEcoLab1* me, /* in */ double_t number) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    double epsilon = 0.0001; // Точность вычислений
    double low = 0.0; // Начальная нижняя граница
    double high = number; // Начальная верхняя граница
    double guess = (low + high) / 2.0; // Начальное предположение

    /* Проверка указателей */
    if (me == NULL) {
        return -1;
    }

    /* Основной алгоритм метода половинного деления */
    while (fabsi(guess * guess * guess - number) >= epsilon) {
        if (guess * guess * guess > number) {
            high = guess;
        } else {
            low = guess;
        }
        guess = (low + high) / 2.0;
    }
    return guess;
}

float_t ECOCALLMETHOD CEcoLab1_CbrtfHalfDivision(/* in */ struct IEcoLab1* me, /* in */ float_t number) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    double epsilon = 0.0001; // Точность вычислений
    double low = 0.0; // Начальная нижняя граница
    double high = number; // Начальная верхняя граница
    double guess = (low + high) / 2.0; // Начальное предположение

    /* Проверка указателей */
    if (me == NULL) {
        return -1;
    }

    /* Основной алгоритм метода половинного деления */
    while (fabsi(guess * guess * guess - number) >= epsilon) {
        if (guess * guess * guess > number) {
            high = guess;
        } else {
            low = guess;
        }
        guess = (low + high) / 2.0;
    }
    return guess;
}
long double ECOCALLMETHOD CEcoLab1_CbrtlHalfDivision(/* in */ struct IEcoLab1* me, /* in */ long double number) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    double epsilon = 0.0001; // Точность вычислений
    double low = 0.0; // Начальная нижняя граница
    double high = number; // Начальная верхняя граница
    double guess = (low + high) / 2.0; // Начальное предположение

    /* Проверка указателей */
    if (me == NULL) {
        return -1;
    }

    /* Основной алгоритм метода половинного деления */
    while (fabsi(guess * guess * guess - number) >= epsilon) {
        if (guess * guess * guess > number) {
            high = guess;
        } else {
            low = guess;
        }
        guess = (low + high) / 2.0;
    }
    return guess;
}
/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCEcoLab1(/*in*/ struct IEcoLab1* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1* pCMe = (CEcoLab1*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
    CEcoLab1_QueryInterface,
    CEcoLab1_AddRef,
    CEcoLab1_Release,
    CEcoLab1_CbrtNewton,
	CEcoLab1_CbrtfNewton,
	CEcoLab1_CbrtlNewton,
	CEcoLab1_CbrtHalfDivision,
	CEcoLab1_CbrtfHalfDivision,
	CEcoLab1_CbrtlHalfDivision

};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCEcoLab1(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IEcoLab1** ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CEcoLab1* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

    /* Инициализация данных */
    pCMe->m_Name = 0;

    /* Возврат указателя на интерфейс */
    *ppIEcoLab1 = (IEcoLab1*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCEcoLab1(/* in */ IEcoLab1* pIEcoLab1) {
    CEcoLab1* pCMe = (CEcoLab1*)pIEcoLab1;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1 != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        if ( pCMe->m_Name != 0 ) {
            pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        }
        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
