﻿#include "FormMain.h"

// Конструктор окна
FormMain::FormMain() : wxFrame(NULL, wxID_ANY, CAPTION, wxDefaultPosition, wxSize(940, 640), wxDEFAULT_FRAME_STYLE)
{
	// иконка
	this->SetIcon(wxICON(wxicon));
	this->SetSizeHints(wxSize(940, 600));

	// главный сайзер окна
	wxBoxSizer* sizerMain = new wxBoxSizer(wxHORIZONTAL);
	{
		splitterLeft = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE | wxSP_3D);

		panelLeftTop = new wxPanel(splitterLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);
		panelLeftBottom = new wxPanel(splitterLeft, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL | wxNO_BORDER);

		// левый верхний сайзер
		wxStaticBoxSizer* sizerLeftTop = new wxStaticBoxSizer(new wxStaticBox(panelLeftTop, wxID_ANY, wxT("Просмотр пакетов")), wxVERTICAL);
		{
			gridCANView = new wxGrid(panelLeftTop, wxID_ANY);
			// параметры сетки
			gridCANView->CreateGrid(0, 10);
			gridCANView->EnableEditing(false);
			gridCANView->EnableGridLines(true);
			gridCANView->EnableDragGridSize(false);
			gridCANView->SetMargins(0, 0);
			// параметры столбцов
			gridCANView->EnableDragColMove(false);
			gridCANView->EnableDragColSize(false);
			gridCANView->SetColLabelSize(20);
			gridCANView->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
			// параметры строк
			gridCANView->EnableDragRowSize(false);
			gridCANView->SetRowLabelSize(40);
			gridCANView->SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
			gridCANView->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
			// заполнение таблицы
			gridCANView->SetColLabelValue(0, wxT("CAN ID"));
			gridCANView->SetColLabelValue(1, wxT("Длина"));
			gridCANView->SetColLabelValue(2, wxT("Байт 0"));
			gridCANView->SetColLabelValue(3, wxT("Байт 1"));
			gridCANView->SetColLabelValue(4, wxT("Байт 2"));
			gridCANView->SetColLabelValue(5, wxT("Байт 3"));
			gridCANView->SetColLabelValue(6, wxT("Байт 4"));
			gridCANView->SetColLabelValue(7, wxT("Байт 5"));
			gridCANView->SetColLabelValue(8, wxT("Байт 6"));
			gridCANView->SetColLabelValue(9, wxT("Байт 7"));
			// установка ширины столбцов
			for (auto iCol = 0; iCol < 10; iCol++)
			{
				gridCANView->SetColSize(iCol, 50);
			}
			sizerLeftTop->Add(gridCANView, 1, wxEXPAND, 0);

			panelLeftTop->SetSizer(sizerLeftTop);
		}
		// левый нижний сайзер
		wxStaticBoxSizer* sizerLeftBottom = new wxStaticBoxSizer(new wxStaticBox(panelLeftBottom, wxID_ANY, wxT("Тестовая отправка пакета и просмотр ответа")), wxVERTICAL);
		{
			// сайзер с текстовыми полями ввода данных CAN-пакета
			wxBoxSizer* sizerLeftBottomText = new wxBoxSizer(wxHORIZONTAL);
			{
				wxStaticText* labelCAN = new wxStaticText(panelLeftBottom, wxID_ANY, wxT("CAN:"), wxDefaultPosition, wxSize(37, 20));
				labelCAN->Wrap(-1);
				sizerLeftBottomText->Add(labelCAN, 0, wxLEFT | wxTOP, 2);
				textCANID = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("7E0"), wxDefaultPosition, wxSize(51, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANID, 0, wxEXPAND, 0);
				textCANLength = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANLength, 0, wxEXPAND, 0);
				textCANByte1 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("05"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte1, 0, wxEXPAND, 0);
				textCANByte2 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("2F"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte2, 0, wxEXPAND, 0);
				textCANByte3 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("00"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte3, 0, wxEXPAND, 0);
				textCANByte4 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("0A"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte4, 0, wxEXPAND, 0);
				textCANByte5 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("06"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte5, 0, wxEXPAND, 0);
				textCANByte6 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("FF"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte6, 0, wxEXPAND, 0);
				textCANByte7 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("00"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte7, 0, wxEXPAND, 0);
				textCANByte8 = new wxTextCtrl(panelLeftBottom, wxID_ANY, wxT("00"), wxDefaultPosition, wxSize(50, 20), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerLeftBottomText->Add(textCANByte8, 0, wxEXPAND, 0);

				sizerLeftBottom->Add(sizerLeftBottomText, 0, wxEXPAND, 0);
			}

			// сайзер с кнопками управления отправкой и журналом ответа
			wxBoxSizer* sizerLeftBottomButtons = new wxBoxSizer(wxHORIZONTAL);
			{
				buttonSend = new wxButton(panelLeftBottom, wxID_ANY, wxT("Отправить CAN-пакет"));
				sizerLeftBottomButtons->Add(buttonSend, 0, wxALL, 4);
				wxStaticText* labelCANFromID = new wxStaticText(panelLeftBottom, wxID_ANY, wxT("Отображать ответ от:"), wxDefaultPosition, wxDefaultSize);
				labelCANFromID->Wrap(-1);
				sizerLeftBottomButtons->Add(labelCANFromID, 0, wxALL, 9);
				textCANAnswerID = new wxTextCtrl(panelLeftBottom, idTEXTCANANSWERID, wxT("7E8"), wxDefaultPosition, wxSize(51, 20), wxTE_CENTRE | wxTE_PROCESS_ENTER | wxBORDER_SIMPLE);
				sizerLeftBottomButtons->Add(textCANAnswerID, 0, wxALL, 7);
				// спейсер между кнопками
				sizerLeftBottomButtons->Add(0, 0, 1, wxEXPAND, 0);
				buttonClearCANLog = new wxButton(panelLeftBottom, wxID_ANY, wxT("Очистить ответ"));
				sizerLeftBottomButtons->Add(buttonClearCANLog, 0, wxALL, 4);

				sizerLeftBottom->Add(sizerLeftBottomButtons, 0, wxEXPAND, 0);
			}


			gridCANLog = new wxGrid(panelLeftBottom, wxID_ANY);
			// параметры сетки
			gridCANLog->CreateGrid(0, 10);
			gridCANLog->EnableEditing(false);
			gridCANLog->EnableGridLines(true);
			gridCANLog->EnableDragGridSize(false);
			gridCANLog->SetMargins(0, 0);
			// параметры столбцов
			gridCANLog->EnableDragColMove(false);
			gridCANLog->EnableDragColSize(false);
			gridCANLog->SetColLabelSize(20);
			gridCANLog->SetColLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
			// параметры строк
			gridCANLog->EnableDragRowSize(false);
			gridCANLog->SetRowLabelSize(40);
			gridCANLog->SetRowLabelAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
			gridCANLog->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
			// заполнение таблицы
			gridCANLog->SetColLabelValue(0, wxT("CAN ID"));
			gridCANLog->SetColLabelValue(1, wxT("Длина"));
			gridCANLog->SetColLabelValue(2, wxT("Байт 0"));
			gridCANLog->SetColLabelValue(3, wxT("Байт 1"));
			gridCANLog->SetColLabelValue(4, wxT("Байт 2"));
			gridCANLog->SetColLabelValue(5, wxT("Байт 3"));
			gridCANLog->SetColLabelValue(6, wxT("Байт 4"));
			gridCANLog->SetColLabelValue(7, wxT("Байт 5"));
			gridCANLog->SetColLabelValue(8, wxT("Байт 6"));
			gridCANLog->SetColLabelValue(9, wxT("Байт 7"));
			// установка ширины столбцов
			for (auto iCol = 0; iCol < 10; iCol++)
			{
				gridCANLog->SetColSize(iCol, 50);
			}
			sizerLeftBottom->Add(gridCANLog, 1, wxEXPAND, 0);

			panelLeftBottom->SetSizer(sizerLeftBottom);
		}

		splitterLeft->SplitHorizontally(panelLeftTop, panelLeftBottom, -1);
		splitterLeft->SetMinimumPaneSize(30);

		sizerMain->Add(splitterLeft, 1, wxALL | wxEXPAND, 4);

		// правый сайзер
		wxBoxSizer* sizerRight = new wxBoxSizer(wxVERTICAL);
		{
			// COM-порт, кнопка управления и статистика буфера
			wxStaticBoxSizer* sizerControls = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Управление")), wxHORIZONTAL);
			{
				textCOM = new wxTextCtrl(this, wxID_ANY, COM_NAME, wxDefaultPosition, wxSize(50, 22), wxTE_CENTRE | wxBORDER_SIMPLE);
				sizerControls->Add(textCOM, 0, wxALL, 2);

				comboBoxSpeed = new wxComboBox(this, wxID_ANY, wxT("500000"), wxDefaultPosition, wxSize(70, 22), 0, NULL, wxTE_CENTRE | wxBORDER_SIMPLE);
				comboBoxSpeed->Append(wxT("57600"));
				comboBoxSpeed->Append(wxT("115200"));
				comboBoxSpeed->Append(wxT("250000"));
				comboBoxSpeed->Append(wxT("500000"));
				comboBoxSpeed->Append(wxT("1000000"));
				comboBoxSpeed->Append(wxT("2000000"));
				sizerControls->Add(comboBoxSpeed, 0, wxALL, 2);

				buttonConnectDisconnect = new wxButton(this, wxID_ANY, wxT("Подключить"));
				sizerControls->Add(buttonConnectDisconnect, 1, wxALL, 0);

				textFPS = new wxTextCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(50, 22), wxTE_CENTRE | wxTE_READONLY | wxBORDER_SIMPLE);
				sizerControls->Add(textFPS, 0, wxALL, 2);

				textBPS = new wxTextCtrl(this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(50, 22), wxTE_CENTRE | wxTE_READONLY | wxBORDER_SIMPLE);
				sizerControls->Add(textBPS, 0, wxALL, 2);

				sizerRight->Add(sizerControls, 0, wxALL | wxEXPAND, 2);
			}

			// журнал, кнопки управления логом и его параметры
			wxStaticBoxSizer* sizerLog = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Запись в журнал и фильтр")), wxVERTICAL);
			{
				wxBoxSizer* sizerLogButtonsList = new wxBoxSizer(wxHORIZONTAL);
				{
					// кнопки журнала
					wxBoxSizer* sizerLogButtons = new wxBoxSizer(wxVERTICAL);
					{
						buttonAdd = new wxButton(this, wxID_ANY, wxT("Добавить ID в фильтр >>"), wxDefaultPosition, wxSize(150, -1));
						sizerLogButtons->Add(buttonAdd, 0, wxALL, 2);

						buttonRemove = new wxButton(this, wxID_ANY, wxT("Убрать ID из фильтра <<"), wxDefaultPosition, wxSize(150, -1));
						sizerLogButtons->Add(buttonRemove, 0, wxALL, 2);

						buttonRemoveAll = new wxButton(this, wxID_ANY, wxT("Очистить фильтр"), wxDefaultPosition, wxSize(150, -1));
						sizerLogButtons->Add(buttonRemoveAll, 0, wxALL, 2);

						sizerLogButtonsList->Add(sizerLogButtons, 0, wxEXPAND, 2);
					}
					// список кадров журнала
					listLog = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), 0, NULL);
					sizerLogButtonsList->Add(listLog, 1, wxALL | wxEXPAND, 2);

					sizerLog->Add(sizerLogButtonsList, 0, wxEXPAND, 2);
				}

				// настройки типа файла журнала
				wxBoxSizer* sizerLogType = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText* labelExt = new wxStaticText(this, wxID_ANY, wxT("Тип файла:"));
					labelExt->Wrap(-1);
					sizerLogType->Add(labelExt, 0, wxALL, 8);

					wxArrayString comboExtChoices;
					comboExtChoices.Add(wxT(".csv"));
					comboExtChoices.Add(wxT(".log"));
					comboExt = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, comboExtChoices);
					comboExt->SetSelection(0);
					logExt = wxT(".csv");
					sizerLogType->Add(comboExt, 0, wxALL, 2);

					wxStaticText* labelSep = new wxStaticText(this, wxID_ANY, wxT("Разделитель:"));
					labelSep->Wrap(-1);
					sizerLogType->Add(labelSep, 0, wxALL, 8);

					wxArrayString comboSepChoices;
					comboSepChoices.Add(wxT(";"));
					comboSepChoices.Add(wxT("Tab"));
					comboSepChoices.Add(wxT("-"));
					comboSepChoices.Add(wxT("_"));
					comboSepChoices.Add(wxT("Space"));

					comboSep = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, comboSepChoices);
					comboSep->SetSelection(0);
					logSeparator = wxT(";");
					sizerLogType->Add(comboSep, 0, wxALL, 2);

					sizerLog->Add(sizerLogType, 0, wxALIGN_CENTER, 2);
				}

				// параметры сохранения данных в лог
				wxBoxSizer* sizerLogParameters = new wxBoxSizer(wxVERTICAL);
				{
					checkSingle = new wxCheckBox(this, wxID_ANY, wxT("Сохранение данных в один файл"));
					checkSingle->SetValue(logSingle);
					sizerLogParameters->Add(checkSingle, 0, wxALL, 5);
					checkDec = new wxCheckBox(this, wxID_ANY, wxT("Десятичный вывод данных"));
					checkDec->SetValue(logDecimal);
					sizerLogParameters->Add(checkDec, 0, wxALL, 5);
					checkASCII = new wxCheckBox(this, wxID_ANY, wxT("Добавлять ASCII данные"));
					checkASCII->SetValue(logASCII);
					sizerLogParameters->Add(checkASCII, 0, wxALL, 5);

					sizerLog->Add(sizerLogParameters, 0, wxALIGN_LEFT, 2);
				}
				sizerRight->Add(sizerLog, 0, wxALL | wxEXPAND, 2);
			}

			// элементы для наглядного представления чисел
			wxStaticBoxSizer* sizerDecoders = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Декодированные значения")), wxVERTICAL);
			{
				// отображение двоичного байта
				wxBoxSizer* sizerDecoderBinByte = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText* labelBinByte = new wxStaticText(this, wxID_ANY, wxT("Двоичный байт:"), wxDefaultPosition, wxSize(120, -1));
					labelBinByte->Wrap(-1);
					sizerDecoderBinByte->Add(labelBinByte, 0, wxALL | wxEXPAND, 3);
					textBinByte = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200, 22), wxTE_CENTRE | wxTE_READONLY | wxBORDER_SIMPLE);
					sizerDecoderBinByte->Add(textBinByte, 0, wxALL | wxEXPAND, 0);
					sizerDecoders->Add(sizerDecoderBinByte, 0, wxALIGN_CENTER | wxALL, 2);
				}

				// отображение десятичного байта
				wxBoxSizer* sizerDecoderDecByte = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText* labelDecByte = new wxStaticText(this, wxID_ANY, wxT("Десятичный байт:"), wxDefaultPosition, wxSize(120, -1));
					labelDecByte->Wrap(-1);
					sizerDecoderDecByte->Add(labelDecByte, 0, wxALL | wxEXPAND, 3);
					textDecByte = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200, 22), wxTE_CENTRE | wxTE_READONLY | wxBORDER_SIMPLE);
					sizerDecoderDecByte->Add(textDecByte, 0, wxALL | wxEXPAND, 0);
					sizerDecoders->Add(sizerDecoderDecByte, 0, wxALIGN_CENTER | wxALL, 2);
				}

				// выбор big endian или little endian
				checkEndian = new wxCheckBox(this, wxID_ANY, wxT("Последовательность байтов big-endian"));
				checkEndian->SetValue(bigEndian);
				sizerDecoders->Add(checkEndian, 0, wxALL, 5);

				// отображение десятичного слова
				wxBoxSizer* sizerDecoderDecWord = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText* labelDecWord = new wxStaticText(this, wxID_ANY, wxT("Десятичное слово:"), wxDefaultPosition, wxSize(120, -1));
					labelDecWord->Wrap(-1);
					sizerDecoderDecWord->Add(labelDecWord, 0, wxALL | wxEXPAND, 3);
					textDecWord = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200, 22), wxTE_CENTRE | wxTE_READONLY | wxBORDER_SIMPLE);
					sizerDecoderDecWord->Add(textDecWord, 0, wxALL | wxEXPAND, 0);
					sizerDecoders->Add(sizerDecoderDecWord, 0, wxALIGN_CENTER | wxALL, 2);
				}

				// множитель десятичного слова
				wxBoxSizer* sizerDecoderWordMul = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText* labelDecWordMul = new wxStaticText(this, wxID_ANY, wxT("Множитель слова:"), wxDefaultPosition, wxSize(120, -1));
					labelDecWordMul->Wrap(-1);
					sizerDecoderWordMul->Add(labelDecWordMul, 0, wxALL | wxEXPAND, 3);
					textDecWordMul = new wxTextCtrl(this, idTEXTDECWORDMUL, wxString::Format(wxT("%1.6f"), mul), wxDefaultPosition, wxSize(200, 22), wxTE_CENTRE | wxTE_PROCESS_ENTER | wxBORDER_SIMPLE);
					sizerDecoderWordMul->Add(textDecWordMul, 0, wxALL | wxEXPAND, 0);
					sizerDecoders->Add(sizerDecoderWordMul, 0, wxALIGN_CENTER | wxALL, 2);
				}

				// результат умножения десятичного слова
				wxBoxSizer* sizerDecoderDecWordResult = new wxBoxSizer(wxHORIZONTAL);
				{
					wxStaticText* labelDecWordResult = new wxStaticText(this, wxID_ANY, wxT("Результат:"), wxDefaultPosition, wxSize(120, -1));
					labelDecWordResult->Wrap(-1);
					sizerDecoderDecWordResult->Add(labelDecWordResult, 0, wxALL | wxEXPAND, 3);
					textDecWordResult = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, 22), wxTE_CENTRE | wxTE_READONLY | wxBORDER_SIMPLE);
					sizerDecoderDecWordResult->Add(textDecWordResult, 0, wxALL | wxEXPAND, 0);
					sizerDecoders->Add(sizerDecoderDecWordResult, 0, wxALIGN_CENTER | wxALL, 2);
				}

				sizerRight->Add(sizerDecoders, 0, wxALL | wxEXPAND, 2);
			}

			// панель для графика
			drawPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
			drawPanel->SetBackgroundColour(wxColour(255, 255, 255));
			sizerRight->Add(drawPanel, 1, wxALL | wxEXPAND, 2);

			sizerMain->Add(sizerRight, 0, wxALL | wxEXPAND, 2);
		}
	}

	this->SetSizer(sizerMain);
	this->SetAutoLayout(true);
	this->Layout();
	this->Centre(wxBOTH);
	this->SetDoubleBuffered(true);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));

	// привязка событий
	gridCANView->Connect(wxEVT_GRID_SELECT_CELL, wxGridEventHandler(FormMain::GridCANView_OnSelectCell), NULL, this);
	buttonConnectDisconnect->Connect(wxEVT_BUTTON, wxCommandEventHandler(FormMain::ButtonConDiscon_OnClick), NULL, this);
	buttonAdd->Connect(wxEVT_BUTTON, wxCommandEventHandler(FormMain::ButtonAdd_OnClick), NULL, this);
	buttonRemove->Connect(wxEVT_BUTTON, wxCommandEventHandler(FormMain::ButtonRemove_OnClick), NULL, this);
	buttonRemoveAll->Connect(wxEVT_BUTTON, wxCommandEventHandler(FormMain::ButtonRemoveAll_OnClick), NULL, this);
	buttonSend->Connect(wxEVT_BUTTON, wxCommandEventHandler(FormMain::ButtonSend_OnClick), NULL, this);
	buttonClearCANLog->Connect(wxEVT_BUTTON, wxCommandEventHandler(FormMain::ButtonClearCANLog_OnClick), NULL, this);
	comboExt->Connect(wxEVT_CHOICE, wxCommandEventHandler(FormMain::ComboExt_OnChoice), NULL, this);
	comboSep->Connect(wxEVT_CHOICE, wxCommandEventHandler(FormMain::ComboSep_OnChoice), NULL, this);
	checkDec->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(FormMain::CheckDec_OnClick), NULL, this);
	checkSingle->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(FormMain::CheckSingle_OnClick), NULL, this);
	checkEndian->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(FormMain::CheckEndian_OnClick), NULL, this);
	checkASCII->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(FormMain::CheckASCII_OnClick), NULL, this);
	drawPanel->Connect(wxEVT_PAINT, wxPaintEventHandler(FormMain::DrawPanel_OnPaint), NULL, this);
	drawPanel->Connect(wxEVT_SIZE, wxSizeEventHandler(FormMain::DrawPanel_OnSize), NULL, this);
	drawPanel->Connect(wxEVT_ERASE_BACKGROUND, wxEraseEventHandler(FormMain::DrawPanel_OnEraseBackground), NULL, this);

	//textDecWordMul->Connect(wxEVT_TEXT_ENTER, wxCommandEventHandler(FormMain::TextDecWordMul_OnEnter), NULL, this);
	//textCANAnswerID->Connect(wxEVT_TEXT_ENTER, wxCommandEventHandler(FormMain::TextCANAnswerID_OnEnter), NULL, this);
	// не получается иначе событие прицепить, приходится через ObjectID делать
	Connect(idTEXTDECWORDMUL, wxEVT_TEXT_ENTER, wxCommandEventHandler(FormMain::TextDecWordMul_OnEnter));
	Connect(idTEXTCANANSWERID, wxEVT_TEXT_ENTER, wxCommandEventHandler(FormMain::TextCANAnswerID_OnEnter));

	// событие от фонового потока COM-порта
	this->Connect(wxEVT_THREAD, wxThreadEventHandler(FormMain::Thread_OnUpdate), NULL, this);
	
	// настройка и запуск таймера
	timerMain = new wxTimer(this, idMAINTIMER);
	Connect(idMAINTIMER, wxEVT_TIMER, wxTimerEventHandler(FormMain::MainTimer_OnTimer));
	timerMain->Start(TIMER_INTERVAL);

	// определение разделителя дробной части чисел
	/*const wxLanguageInfo* langInfo = wxLocale::GetLanguageInfo(wxLocale::GetSystemLanguage());
	wxChar sepBuf[256] { 0 };
	GetLocaleInfo(langInfo->GetLCID(), LOCALE_SDECIMAL, sepBuf, WXSIZEOF(sepBuf));
	decimalSeparator = sepBuf;*/
	
	// для русского языка определяется запятая, как и положено
	// эта запятая и ставится в друбную часть времени в файл, разделяя секунды и миллисекунды
	// вот только Excel не понимает этого и неверно отображает миллисекунды
	// поэтому разделителем ставлю точку
	decimalSeparator = wxT(".");
}

// Деструктор окна
FormMain::~FormMain()
{
	timerMain->Stop();
	if (COM)
		COM->Delete();

	// записать все файлы
	FlushLogs();
}

/*--------------------------------------------------------------------------------------------------*/

// Обработчик кнопки Подключить/отключить
void FormMain::ButtonConDiscon_OnClick(wxCommandEvent& event)
{
	try
	{
		// если порт не открыт - открыть, иначе - закрыть
		if (COM == NULL)
		{
			DWORD comSpeed = 0;
			if (comboBoxSpeed->GetValue().ToULong(&comSpeed, 10))
			{
				frames.reserve(DRAW_DATA_RESERV);
				frames.clear();
				drawData.reserve(DRAW_DATA_RESERV);
				drawData.clear();
				drawData.shrink_to_fit();
				drawDataBegin = 0;

				// удалить все строки таблицы
				if (gridCANView->GetNumberRows() > 0)
				{
					gridCANView->DeleteRows(0, gridCANView->GetNumberRows());
				}

				COM = new ThreadedSerialPort(textCOM->GetValue(), comSpeed, (wxFrame*)this);
				buttonConnectDisconnect->SetLabelText(wxT("Отключить"));
				rowToView = -1;
				colToView = -1;
			}
		}
		else
		{
			if (COM->hSerial != INVALID_HANDLE_VALUE)
			{
				COM->Delete();
			}
			delete COM;
			COM = NULL;
			drawData.reserve(DRAW_DATA_RESERV);
			drawData.clear();
			drawData.shrink_to_fit();
			drawDataBegin = 0;
			buttonConnectDisconnect->SetLabelText(wxT("Подключить"));

			// записать все log-файлы
			FlushLogs();
			logFiles.clear();
		}
	}
	catch (...)
	{
		wxMessageBox(wxT("Невозможно работать с этим COM-портом"));
	}
}

// По событию от потока забирать все принятые CAN-пакеты, которые есть в буфере
void FormMain::Thread_OnUpdate(wxThreadEvent& event)
{
	CANFrame frame;

	if (COM)
	{
		while (COM->GetNextFrame(&frame))
		{	
			ProcessCANFrame(&frame);			
		}
	}
}

// Проверка поступившего CAN-пакета
void FormMain::ProcessCANFrame(CANFrame* Frame)
{
	bool found = false;

	// если это пакет с адресом 000 - это статистика и её надо вывести отдельно
	if (Frame->ID == 0 && Frame->Length >= 4)
	{
		uint16_t fps = (Frame->Data[0] << 8) + Frame->Data[1];
		textFPS->SetValue(wxString::Format(wxT("%i"), fps));	// кадров в секунду
		uint16_t bps = (Frame->Data[2] << 8) + Frame->Data[3];
		textBPS->SetValue(wxString::Format(wxT("%i"), bps));	// байтов в секунду
	}
	else
	{
		// поиск ID в списке
		size_t idCount = frames.size();
		for (uint32_t iID = 0; iID < idCount; iID++)
		{
			// если найден - выделить яркостью цета изменяющиеся данные и заменить CAN-пакет
			if (frames[iID].ID == Frame->ID)
			{
				gridCANView->SetCellValue(iID, 1, wxString::Format(wxT("%i"), Frame->Length));	// длина пакета
				for (uint32_t i = 0; i < 8; i++)
				{
					if (i < Frame->Length)
					{
						gridCANView->SetCellValue(iID, i + 2, wxString::Format(wxT("%02X"), Frame->Data[i]));
						// если новые данные такие же - необходимо плавно осветлять фоновую заливку
						if (Frame->Data[i] == frames[iID].Data[i])
						{
							byte tick = frames[iID].Tick[i];
							if (tick < 255)
							{
								tick++;
							}

							gridCANView->SetCellBackgroundColour(iID, i + 2, wxColor(MARKED_COLOR, tick, tick));
							Frame->Tick[i] = tick;
						}
						else
						{
							gridCANView->SetCellBackgroundColour(iID, i + 2, wxColor(MARKED_COLOR));
						}
					}
					else
					{
						gridCANView->SetCellValue(iID, i + 2, wxT(" "));
						gridCANView->SetCellBackgroundColour(iID, i + 2, wxColor(DEFAULT_COLOR));
					}
					// для wxWidhets 3.1.2 это строка не нужна
					// проблема с обновлением фона ячейки появилась в связи с изменениемя контрола wxGrid в версии wxWidgets 3.1.3
					gridCANView->RefreshBlock(iID, i + 2, iID, i + 2);
				}

				frames[iID] = *Frame;
				found = true;
				break;
			}
		}

		// если ID не найден - добавить новый
		if (!found)
		{
			// добавить элемент в массив и отсортировать его
			frames.push_back(*Frame);
			sort(frames.begin(), frames.end());
			idCount = frames.size();

			// теперь надо снова найти элемент в отсортированном массиве, чтобы корректно вставить строку в таблицу
			for (uint32_t iID = 0; iID < idCount; iID++)
			{
				if (frames[iID].ID == Frame->ID)
				{
					gridCANView->InsertRows(iID);

					gridCANView->SetCellValue(iID, 0, wxString::Format(wxT("%03X"), Frame->ID));
					gridCANView->SetCellValue(iID, 1, wxString::Format(wxT("%i"), Frame->Length));

					// заполнение столбцов параметров
					for (uint32_t iData = 0; iData < 8; iData++)
					{
						if (iData < Frame->Length)
						{
							gridCANView->SetCellValue(iID, iData + 2, wxString::Format(wxT("%02X"), Frame->Data[iData]));
							gridCANView->SetCellBackgroundColour(iID, iData + 2, wxColor(NEW_COLOR));
						}
						else
						{
							gridCANView->SetCellValue(iID, iData + 2, wxT(" "));
							gridCANView->SetCellBackgroundColour(iID, iData + 2, wxColor(DEFAULT_COLOR));
						}
					}
					break;
				}
			}
		}
		// показать числа в разных форматах
		ShowNumbers();

		// запись в лог по необходимости
		
		// если в фильтре ничего не выбрано - запись всех данных
		if (logFilterIDs.size() == 0)
		{
			SaveToLog(Frame);
		}
		// иначе - записывать пакеты указанные в фильтре
		else
		{
			for (uint32_t iLog = 0; iLog < logFilterIDs.size(); iLog++)
			{
				if (Frame->ID == logFilterIDs[iLog])
				{
					SaveToLog(Frame);
				}
			}
		}

		// если ожидается ответ от этого ID - добавить его в список ответов
		if (Frame->ID == answerID)
		{
			int32_t index = gridCANLog->GetNumberRows();
			gridCANLog->InsertRows(index);

			gridCANLog->SetCellValue(index, 0, wxString::Format(wxT("%03X"), Frame->ID));
			gridCANLog->SetCellValue(index, 1, wxString::Format(wxT("%i"), Frame->Length));

			// заполнение столбцов параметров
			for (unsigned int i = 0; i < 8; i++)
			{
				if (i < Frame->Length)
				{
					gridCANLog->SetCellValue(index, i + 2, wxString::Format(wxT("%02X"), Frame->Data[i]));
					//gridCANLog->SetCellBackgroundColour(index, i + 2, wxColor(DEFAULT_COLOR));
				}
			}
			// прокрутить список вниз
			gridCANLog->MakeCellVisible(gridCANLog->GetNumberRows() - 1, 0);
		}
	}
}

// Отображение выделенной ячейки в разных форматах
void FormMain::ShowNumbers()
{
	if (rowToView >= 0 && colToView >= 0)
	{
		// если полученных данных ещё нет
		if (rowToView >= (int)frames.size())
		{
			return;
		}

		uint8_t firstByte = frames[rowToView].Data[colToView];
		uint8_t secondByte = colToView < 7 ? frames[rowToView].Data[colToView + 1] : 0;

		// выбор между big endian и little endian
		uint32_t value = bigEndian ? (firstByte << 8) + secondByte : (secondByte << 8) + firstByte;

		textDecWord->SetValue(wxString::Format(wxT("%i"), value));
		uint32_t mulValue = (uint32_t)((double)value * mul);
		textDecWordResult->SetValue(wxString::Format(wxT("%i"), mulValue));

		textBinByte->SetValue(ToBinary(firstByte));
		textDecByte->SetValue(wxString::Format(wxT("%i"), firstByte));

		// добавить полученные данные в очередь на отрисовку
		drawData.push_back(mulValue);
	}
}

// Обновляет список ID для записи в log
void FormMain::RefreshListLog()
{
	sort(logFilterIDs.begin(), logFilterIDs.end());
	listLog->Clear();
	for (uint32_t i = 0; i < logFilterIDs.size(); i++)
	{
		listLog->Append(wxString::Format(wxT("%03X"), logFilterIDs[i]));
	}
}

// При нажатии Enter в поле ввода множителя - обработать его и запомнить
void FormMain::TextDecWordMul_OnEnter(wxCommandEvent& event)
{
	textDecWordMul->GetValue().ToDouble(&mul);

	if (mul == 0)
		mul = 1.0;
	else if (mul > 10000)
		mul = 10000.0;

	textDecWordMul->SetValue(wxString::Format(wxT("%1.6f"), mul));
	drawMaxValue = 0;
}

// Добавить ID в список фильра для записи в log
void FormMain::ButtonAdd_OnClick(wxCommandEvent& event)
{
	int32_t index = -1;

	if (rowToLog >= 0 && (int)frames.size() > rowToLog)
	{
		bool found = false;
		for (uint32_t iIDs = 0; iIDs < logFilterIDs.size(); iIDs++)
		{
			if (frames[rowToLog].ID == logFilterIDs[iIDs])
			{
				found = true;
				break;
			}
		}
		if (!found)
			logFilterIDs.push_back(frames[rowToLog].ID);
	}

	RefreshListLog();
}

// Удалить ID из списка фильтра записи в log
void FormMain::ButtonRemove_OnClick(wxCommandEvent& event)
{
	int32_t index = listLog->GetSelection();

	if (index > -1)
	{
		logFilterIDs.erase(logFilterIDs.begin() + index);
	}

	RefreshListLog();
}

// Очистить весь список фильтра записи в log
void FormMain::ButtonRemoveAll_OnClick(wxCommandEvent& event)
{
	logFilterIDs.clear();
	RefreshListLog();
}

// Выбор расширения файла
void FormMain::ComboExt_OnChoice(wxCommandEvent& event)
{
	logExt = event.GetString();
}

// Выбор разделителя в log-файле
void FormMain::ComboSep_OnChoice(wxCommandEvent& event)
{
	wxString value = event.GetString();
	if (value == wxT("Tab"))
		logSeparator = wxT("\t");
	else if (value == wxT("Space"))
		logSeparator = wxT(" ");
	else
		logSeparator = value;
}

// Клик по десятичной форме записи log
void FormMain::CheckDec_OnClick(wxCommandEvent& event)
{
	logDecimal = checkDec->IsChecked();
}

// Клик по выводу в один файл
void FormMain::CheckSingle_OnClick(wxCommandEvent& event)
{
	logSingle = checkSingle->IsChecked();
}

// Клик для добавления в log-файл ASCII данных
void FormMain::CheckASCII_OnClick(wxCommandEvent& event)
{
	logASCII = checkASCII->IsChecked();
}

// Клик по выбору big endian или little endian
void FormMain::CheckEndian_OnClick(wxCommandEvent& event)
{
	bigEndian = checkEndian->IsChecked();
}

// Записать в log указанный CAN-пакет
void FormMain::SaveToLog(CANFrame* Frame)
{
	// если запись в один файл...
	if (logSingle)
	{
		// если файл существует - записать данные
		if (logFile)
		{
			LogWriteLine(logFile, Frame);
		}
		else
		{
			// сначала создать файл
			try
			{
				string logPath = wxGetCwd() + wxT("\\CAN") + logExt;

				logFile = new wxFFile();
				if (logFile->Open(logPath, wxT("a")))
				{
					logFile->SeekEnd();
					LogWriteLine(logFile, Frame);
				}
			}
			catch (...) {}
		}
	}
	else
	{
		// запись в разные файлы
		bool found = false;

		for (uint32_t iFile = 0; iFile < logFiles.size(); iFile++)
		{
			// проверка существования потока
			if (logFiles[iFile].ID == Frame->ID)
			{
				// если файл для этого кадра уже существует - просто дописать в него данные
				LogWriteLine(logFiles[iFile].File, Frame);

				found = true;
				break;
			}
		}

		// если файл не существует - сначала создать его, а потом записать строку
		if (!found)
		{
			try
			{
				string logPath = wxGetCwd() + wxT("\\CAN ID ") + wxString::Format(wxT("%03X"), Frame->ID) + logExt;

				LogFile newLogFile;
				newLogFile.File = new wxFFile();
				if (newLogFile.File->Open(logPath, wxT("a")))
				{
					newLogFile.File->SeekEnd();
					newLogFile.ID = Frame->ID;
					logFiles.push_back(newLogFile);
					LogWriteLine(logFiles[logFiles.size() - 1].File, Frame);
				}
			}
			catch (...) {}
		}
	}
}

// Записать в журнал строку данных
void FormMain::LogWriteLine(wxFFile* File, CANFrame* Frame)
{
	// штамп времени
	wxDateTime dtNow = wxDateTime::UNow();
	//wxString newLine = dtNow.FormatDate() + separator + dtNow.FormatTime() + wxT(".") + wxString::Format(wxT("%03i"), dtNow.GetMillisecond()) + separator;
	wxString newLine = dtNow.FormatTime() + decimalSeparator + wxString::Format(wxT("%03i"), dtNow.GetMillisecond()) + logSeparator;

	try
	{
		// идентификатор пакета и его длина
		newLine += wxString::Format(wxT("%03X"), Frame->ID) + logSeparator;
		newLine += wxString::Format(wxT("%i"), Frame->Length) + logSeparator;
		// данные пакета
		for (uint32_t iData = 0; iData < Frame->Length; iData++)
		{
			if (logDecimal)
			{
				// десятичный вывод
				newLine += wxString::Format(wxT("%0i"), Frame->Data[iData]) + logSeparator;
			}
			else
			{
				// шестнадцатиричный вывод
				newLine += wxString::Format(wxT("%02X"), Frame->Data[iData]) + logSeparator;
			}
		}

		// если надо сохранять ASCII данные
		std::string buf;
		if (logASCII)
		{
			// дополнить строку разделителями для выравнивания
			for (uint32_t iData = Frame->Length; iData < 8; iData++)
			{
				newLine += logSeparator;
			}
			newLine += '|' + logSeparator;

			// добавить ASCII данные из пакета
			buf = newLine.ToStdString();
			for (uint32_t iData = 0; iData < Frame->Length; iData++)
			{
				if (Frame->Data[iData] > 0x1F)
				{
					buf += Frame->Data[iData];
				}
				else
				{
					buf += ' ';
				}
			}
		}
		else
		{
			// данные без ASCII
			buf = newLine.ToStdString();
		}

		buf += "\n";
		File->Write(buf.c_str(), buf.size());
		File->Flush();
	}
	catch (...) { }
}

// Сбрасывает на диск данные и закрывает все файлы log-ов
void FormMain::FlushLogs()
{
	// сбросить данные на диск для массива логов
	for (uint32_t iFile = 0; iFile < logFiles.size(); iFile++)
	{
		logFiles[iFile].File->Flush();
		logFiles[iFile].File->Close();
		delete logFiles[iFile].File;
		logFiles[iFile].File = NULL;
	}

	// сохранить всё, если лог один
	if (logFile)
	{
		logFile->Flush();
		logFile->Close();
		delete logFile;
		logFile = NULL;
	}
}

// Выбор ячейки в таблице
void FormMain::GridCANView_OnSelectCell(wxGridEvent& event)
{
	// запомнить строку для добавления в log
	rowToLog = event.GetRow();

	rowToView = rowToLog;
	colToView = event.GetCol() - 2;
	// если выбран столбик не с данными
	if (colToView < 0)
	{
		rowToView = -1;
		colToView = -1;
		
		textBinByte->SetValue(wxT(""));
		textDecByte->SetValue(wxT(""));
		textDecWord->SetValue(wxT(""));
	}
	else
	{
		// показать числа в разных форматах
		ShowNumbers();

		// очистка данных на отрисовку
		drawData.clear();
		drawData.shrink_to_fit();
		drawDataBegin = 0;
		drawMaxValue = 0;
	}
}

// Преобразовывает байт в двоичное представление
wxString FormMain::ToBinary(uint8_t Value)
{
	wxString binaryString;
	
	for (uint32_t counter = 0; counter < 4; counter++)
	{
		if (Value & 0x80)	binaryString += wxT('1');
		else				binaryString += wxT('0');
		Value <<= 1;
	}
	binaryString += wxT('_');
	for (uint32_t counter = 0; counter < 4; counter++)
	{
		if (Value & 0x80)	binaryString += wxT('1');
		else				binaryString += wxT('0');
		Value <<= 1;
	}
	return binaryString;
}

// Срабатывание таймера
void FormMain::MainTimer_OnTimer(wxTimerEvent& event)
{
	drawPanel->Refresh(true, &drawRect);
	if (COM != NULL && !COM->IsAlive())
	{
		COM->Delete();
		delete COM;
		COM = NULL;
		buttonConnectDisconnect->SetLabelText(wxT("Подключить"));
	}
}

// Событие отрисовки в панели графика
void FormMain::DrawPanel_OnPaint(wxPaintEvent& event)
{
	//wxPaintDC dc(drawPanel);
	wxBufferedPaintDC dc(drawPanel);	// с буферной отрисовкой выглядит лучше

	PrepareDC(dc);

	// нарисовать рамку и фон
	dc.SetPen(*wxBLACK);
	dc.DrawRectangle(drawRect);
	
	size_t drawDataSize = drawData.size();
	if (drawDataSize > 0)
	{
		// если размер массива больше чем окно рисования - сдвинуть указатель на начало данных
		if (drawDataSize >= (size_t)drawRect.width)
		{
			drawDataBegin = drawDataSize - drawRect.width;
		}

		double drawMul = 1;
		if (drawMaxValue != 0)
		{
			drawMul = (double)drawRect.height / drawMaxValue;
		}

		dc.SetPen(wxPen(wxColor(DRAW_COLOR, 0, 0), 3));

		for (int32_t index = 1; (index < drawRect.width) && (index < (int)drawDataSize - 1); index++)
		{
			// рисовать отмасштабированную линию
			dc.DrawLine(drawRect.x + index, drawRect.y + drawRect.height - drawData[drawDataBegin + index - 1] * drawMul,
						drawRect.x + index, drawRect.y + drawRect.height - drawData[drawDataBegin + index] * drawMul);
			
			// сохранение наибольшего значения для следующей итерации
			if (drawData[drawDataBegin + index] > drawMaxValue)
			{
				drawMaxValue = drawData[drawDataBegin + index];
			}
		}
	}
}

// Изменение размеров панели графика
void FormMain::DrawPanel_OnSize(wxSizeEvent& event)
{
	drawRect = drawPanel->GetClientRect();
	this->Refresh(true, &drawRect);
	//event.Skip();
}

// Стирание фона панели графика
void FormMain::DrawPanel_OnEraseBackground(wxEraseEvent& event)
{
	// кода нет, используется как заглушка
}

// Нажатие кнопки очистки ответа на отправленный пакет
void FormMain::ButtonClearCANLog_OnClick(wxCommandEvent& event)
{
	// удалить все строки таблицы
	if (gridCANLog->GetNumberRows() > 0)
	{
		gridCANLog->DeleteRows(0, gridCANLog->GetNumberRows());
	}
}

// Нажатие кнопки отправки CAN-пакета
void FormMain::ButtonSend_OnClick(wxCommandEvent& event)
{
	long tempValue;

	// собрать CAN-пакет для отправки
	CANFrame frame = { 0 };

	// ID пакета
	textCANID->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0x7FFF)
		frame.ID = (unsigned int)tempValue;
	else
		return;
	// длина данных пакета
	textCANLength->GetValue().ToLong(&tempValue, 10);
	if (tempValue >= 0 && tempValue <= 8)
		frame.Length = (byte)tempValue;
	else
		return;
	// байт 1
	textCANByte1->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[0] = (byte)tempValue;
	else
		return;
	// байт 2
	textCANByte2->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[1] = (byte)tempValue;
	else
		return;
	// байт 3
	textCANByte3->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[2] = (byte)tempValue;
	else
		return;
	// байт 4
	textCANByte4->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[3] = (byte)tempValue;
	else
		return;
	// байт 5
	textCANByte5->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[4] = (byte)tempValue;
	else
		return;
	// байт 6
	textCANByte6->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[5] = (byte)tempValue;
	else
		return;
	// байт 7
	textCANByte7->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[6] = (byte)tempValue;
	else
		return;
	// байт 8
	textCANByte8->GetValue().ToLong(&tempValue, 16);
	if (tempValue >= 0 && tempValue <= 0xFF)
		frame.Data[7] = (byte)tempValue;
	else
		return;
	// запомнить ID пакета, от которого ожидается ответ
	textCANAnswerID->GetValue().ToLong(&tempValue, 16);
	if (tempValue > 0 && tempValue <= 0x7FFF)
		answerID = (unsigned int)tempValue;
	else
		answerID = 0;
	
	// отправить данные
	if (COM)
	{
		COM->SendFrame(&frame);
	}
}

// нажатие Enter при вводе номера CAN ID ожидания ответа
void FormMain::TextCANAnswerID_OnEnter(wxCommandEvent& event)
{
	textCANAnswerID->GetValue().ToCULong((unsigned long*)&answerID, 16);
	textCANAnswerID->SetValue(wxString::Format(wxT("%03X"), answerID));
}

