/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1Sink
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1Sink
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2016 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "CEcoLab1Sink.h"
#include "IEcoConnectionPointContainer.h"

#define BACKGROUND_ORANGE 0x0060

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_QueryInterface(/* in */ struct IEcoLab1Events* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    if ( IsEqualUGUID(riid, &IID_IEcoLab1Events ) ) {
        *ppv = me;
        me->pVTbl->AddRef(me);
        return 0;
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown ) ) {
        *ppv = me;
        me->pVTbl->AddRef(me);
        return 0;
    }

    *ppv = 0;

    return -1;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1Sink_AddRef(/* in */ struct IEcoLab1Events* me) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    pCMe->m_cRef++;
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CEcoLab1Sink_Release(/* in */ struct IEcoLab1Events* me) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;

    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCEcoLab1Sink((IEcoLab1Events*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}
int16_t ECOCALLMETHOD CEcoLab1Sink_OnPrintType(/* in */ struct IEcoLab1Events* me, /* in */ int16_t num){
	CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;
	// Настройка вывода в консоль
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    if (me == 0 ) {
        return -1;
    }

	// Сохранение текущих атрибутов
    GetConsoleScreenBufferInfo(handle, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(handle, BACKGROUND_BLUE);

	if(num == 1){
		printf("Newton method\n");
	}
	else if(num == 2){
		printf("Binary method\n");
	}

	// Восстановление атрибутов
	SetConsoleTextAttribute(handle, saved_attributes);

    return 0;
}
int16_t ECOCALLMETHOD CEcoLab1Sink_OnPrintDataBefore(/* in */ struct IEcoLab1Events* me, /* in */ double_t number, /* in */ double_t epsilon){
	CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;
	// Настройка вывода в консоль
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

	if (me == 0 ) {
        return -1;
    }

	// Сохранение текущих атрибутов
    GetConsoleScreenBufferInfo(handle, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(handle, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	printf("Initial data:\n");
	// Восстановление атрибутов
	SetConsoleTextAttribute(handle, saved_attributes);
	printf("Number: %Lf ", number);
	printf("Epsilon: %Lf ", epsilon);
	printf("\n");

	// Восстановление атрибутов
	SetConsoleTextAttribute(handle, saved_attributes);

    return 0;
}
int16_t ECOCALLMETHOD CEcoLab1Sink_OnPrintDataAfter(/* in */ struct IEcoLab1Events* me, /* in */ double_t number){
	CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;
	size_t i = 0;
	// Настройка вывода в консоль
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

	if (me == 0 ) {
        return -1;
    }

	// Сохранение текущих атрибутов
    GetConsoleScreenBufferInfo(handle, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	printf("\n");
	SetConsoleTextAttribute(handle, BACKGROUND_RED| BACKGROUND_INTENSITY);
	printf("Final value\n");

	// Восстановление атрибутов
	SetConsoleTextAttribute(handle, saved_attributes);

	printf("%Lf \n",number);

	// Восстановление атрибутов
	SetConsoleTextAttribute(handle, saved_attributes);

    return 0;
}
int16_t ECOCALLMETHOD CEcoLab1Sink_CurrentState(/* in */ struct IEcoLab1* me, /* in */ int16_t index,double_t x,double_t epsilon){
	CEcoLab1Sink* pCMe = (CEcoLab1Sink*)me;
	size_t i = 0, j = 0;
	// Настройка вывода в консоль
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

	if (me == 0 ) {
        return -1;
    }

	// Сохранение текущих атрибутов
    GetConsoleScreenBufferInfo(handle, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	if(index != 1){
		printf("\r");
	}
	SetConsoleTextAttribute(handle, BACKGROUND_ORANGE);
	printf("Step");
	SetConsoleTextAttribute(handle, saved_attributes);
	printf(": %d  ",index);
	SetConsoleTextAttribute(handle, BACKGROUND_ORANGE);
	printf("Rezult");
	SetConsoleTextAttribute(handle, saved_attributes);
	printf(": %Lf ",x);
	Sleep(1200);
    return 0;
}
/*
 *
 * <сводка>
 *   Функция Advise
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_Advise(/* in */ struct CEcoLab1Sink* me, /* in */IEcoLab1 *pIEcoLab1) {
    IEcoConnectionPointContainer* pCPC = 0;
    IEcoConnectionPoint* pCP = 0;
    int16_t result = 0;

    result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoConnectionPointContainer, (void**)&pCPC);

    if (result == 0 && pCPC != 0) {
        result = pCPC->pVTbl->FindConnectionPoint(pCPC, &IID_IEcoLab1Events, &pCP);
        pCPC->pVTbl->Release(pCPC);
        pCPC = 0;
        if (result == 0 && pCP != 0) {

            result = pCP->pVTbl->Advise(pCP, (IEcoUnknown*)me, &me->m_cCookie);
            pCP->pVTbl->Release(pCP);
            pCP = 0;
        }
    }

    return result;
}

/*
 *
 * <сводка>
 *   Функция Unadvise
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CEcoLab1Sink_Unadvise(/* in */ struct CEcoLab1Sink* me, /* in */IEcoLab1 *pIEcoLab1) {
    IEcoConnectionPointContainer* pCPC = 0;
    IEcoConnectionPoint * pCP = 0;
    int16_t result = 0;

    if (me->m_cCookie) {
        result = pIEcoLab1->pVTbl->QueryInterface(pIEcoLab1, &IID_IEcoConnectionPointContainer, (void**)&pCPC);
        if (result == 0) {
            result = pCPC->pVTbl->FindConnectionPoint(pCPC, &IID_IEcoLab1Events, &pCP);
            pCPC->pVTbl->Release(pCPC);
            pCPC = 0;
            if (result == 0) {
                result = pCP->pVTbl->Unadvise(pCP, me->m_cCookie);
                pCP->pVTbl->Release(pCP);
                pCP = 0;
            }
        }
    }
    return result;
}

/* Create Virtual Table IEcoLab1VTblEvents */
IEcoLab1VTblEvents g_x2D2E3B9214F248A6A09ECB494B59C795VTblEvents = {
    CEcoLab1Sink_QueryInterface,
    CEcoLab1Sink_AddRef,
    CEcoLab1Sink_Release,
	CEcoLab1Sink_OnPrintType,
	CEcoLab1Sink_OnPrintDataBefore,
	CEcoLab1Sink_CurrentState,
	CEcoLab1Sink_OnPrintDataAfter
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
int16_t ECOCALLMETHOD createCEcoLab1Sink(/* in */ IEcoMemoryAllocator1* pIMem, /* out */ IEcoLab1Events** ppIEcoLab1Events) {
    int16_t result = -1;
    CEcoLab1Sink* pCMe = 0;

    /* Проверка указателей */
    if (ppIEcoLab1Events == 0 || pIMem == 0 ) {
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1Sink*)pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1Sink));

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;
    pCMe->m_pIMem->pVTbl->AddRef(pCMe->m_pIMem);

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IEcoP2PEvents */
    pCMe->m_pVTblIEcoLab1Events = &g_x2D2E3B9214F248A6A09ECB494B59C795VTblEvents;

    *ppIEcoLab1Events = (IEcoLab1Events*)pCMe;

    return 0;
};

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
void ECOCALLMETHOD deleteCEcoLab1Sink(IEcoLab1Events* pIEcoLab1Events) {
    CEcoLab1Sink* pCMe = (CEcoLab1Sink*)pIEcoLab1Events;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIEcoLab1Events != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
};
