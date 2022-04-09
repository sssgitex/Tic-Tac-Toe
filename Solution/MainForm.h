#pragma once
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <string>
#include <windows.h>


namespace krestiki {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	
	int move = 0;
	int moveNum = 0;
	int player1Full = 0;
	int player2Full = 0;
	int gameStart = 0;
	int GameArr[3][3] = { {0,0,0} , {0,0,0} , {0,0,0} };
	int FreeSpace = 0;
	int GameEnd = 0;
	int GameWinner = 0;
	int GameDraw = 0;
	int stopper = 0;
	int frstMove;
	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ Panel;
	protected:

	private: System::Windows::Forms::Button^ btUpperLeft;
	private: System::Windows::Forms::Button^ btUpper;
	private: System::Windows::Forms::Button^ btUpperRight;
	private: System::Windows::Forms::Button^ btLeft;
	private: System::Windows::Forms::Button^ btCentr;
	private: System::Windows::Forms::Button^ btRight;
	private: System::Windows::Forms::Button^ btDownLeft;
	private: System::Windows::Forms::Button^ btDown;
	private: System::Windows::Forms::Button^ btDownRight;
	private: System::Windows::Forms::Label^ lbnName;
	private: System::Windows::Forms::Label^ lbMain;
	private: System::Windows::Forms::Button^ btSTART;
	private: System::Windows::Forms::Button^ btRESTART;


	private: System::Windows::Forms::TextBox^ tbPlayer1;
	private: System::Windows::Forms::TextBox^ tbPlayer2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	protected:










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		
		//int HideConsole() {
		//	ShowWindow(GetConsoleWindow(), SW_HIDE);
		//	return 0;
		//}

		void NamingVar() {
			move = 0;
			moveNum = 0;
			//player1Full = 0;
			//player2Full = 0;
			gameStart = 0;
			FreeSpace = 0;
			GameEnd = 0;
			GameWinner = 0;
			GameDraw = 0;
			stopper = 0;
		}
		int fcRand() {
			srand((unsigned)time(0));
			int rNumb;
			rNumb = (rand() % 2) + 1;
			return rNumb;
		}
		String^ p1Name() {
			String^ player1 = this->tbPlayer1->Text;
			/*if (player1 != "")
			{
				player1Full = 1;
			}*/
			return player1;
		}
		String^ p2Name() {
			String^ player2 = this->tbPlayer2->Text;
			/*if (player2 != "")
			{
				player2Full = 1;
			}*/
			return player2;
		}
		int nxtMove(int move1) {
			int x = move1;
			if (x == 1) {
				x++;
				this->lbMain->Text = this->tbPlayer2->Text + " turn (O)";
			}
			else if (x == 2) {
				x--;
				this->lbMain->Text = this->tbPlayer1->Text + " turn (X)";
			}
			return x;
		}
		void MoveNum() {
			moveNum++;
			if (moveNum == 9) {
				GameEnd = 1;
				GameDraw = 1;
			}
				
		}
		void ReadyGameStart() {
			if ((this->tbPlayer1->Text != "") && (this->tbPlayer2->Text != "")) {
				gameStart = 1;
			}
		}
		void GameResult() {
			if		((GameArr[0][0] == 1) && (GameArr[0][1] == 1) && (GameArr[0][2] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			else if ((GameArr[1][0] == 1) && (GameArr[1][1] == 1) && (GameArr[1][2] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			else if ((GameArr[2][0] == 1) && (GameArr[2][1] == 1) && (GameArr[2][2] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			else if ((GameArr[0][0] == 1) && (GameArr[1][0] == 1) && (GameArr[2][0] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			else if ((GameArr[0][1] == 1) && (GameArr[1][1] == 1) && (GameArr[2][1] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			else if ((GameArr[0][2] == 1) && (GameArr[1][2] == 1) && (GameArr[2][2] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			else if ((GameArr[0][0] == 1) && (GameArr[1][1] == 1) && (GameArr[2][2] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			else if ((GameArr[0][2] == 1) && (GameArr[1][1] == 1) && (GameArr[2][0] == 1)) {
				GameEnd = 1;
				GameWinner = 1;
			}
			//------------------------------------------------------------------------------
			if		((GameArr[0][0] == 2) && (GameArr[0][1] == 2) && (GameArr[0][2] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			else if ((GameArr[1][0] == 2) && (GameArr[1][1] == 2) && (GameArr[1][2] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			else if ((GameArr[2][0] == 2) && (GameArr[2][1] == 2) && (GameArr[2][2] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			else if ((GameArr[0][0] == 2) && (GameArr[1][0] == 2) && (GameArr[2][0] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			else if ((GameArr[0][1] == 2) && (GameArr[1][1] == 2) && (GameArr[2][1] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			else if ((GameArr[0][2] == 2) && (GameArr[1][2] == 2) && (GameArr[2][2] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			else if ((GameArr[0][0] == 2) && (GameArr[1][1] == 2) && (GameArr[2][2] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			else if ((GameArr[0][2] == 2) && (GameArr[1][1] == 2) && (GameArr[2][0] == 2)) {
				GameEnd = 1;
				GameWinner = 2;
			}
			
		}
		void ClearArr() {
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					GameArr[i][j] = 0;
				}
			}
			
		};
		/*void FreeSpaces() {
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (GameArr[i][j] != 0) {
						FreeSpace++;
					}
				}
			}
			if (FreeSpace == 21) {
				GameEnd = 1;
				GameWinner = 3;
			}
		}*/
		void InitializeComponent(void)
		{	
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->Panel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btUpperLeft = (gcnew System::Windows::Forms::Button());
			this->btUpper = (gcnew System::Windows::Forms::Button());
			this->btUpperRight = (gcnew System::Windows::Forms::Button());
			this->btLeft = (gcnew System::Windows::Forms::Button());
			this->btCentr = (gcnew System::Windows::Forms::Button());
			this->btRight = (gcnew System::Windows::Forms::Button());
			this->btDownLeft = (gcnew System::Windows::Forms::Button());
			this->btDown = (gcnew System::Windows::Forms::Button());
			this->btDownRight = (gcnew System::Windows::Forms::Button());
			this->lbnName = (gcnew System::Windows::Forms::Label());
			this->lbMain = (gcnew System::Windows::Forms::Label());
			this->btSTART = (gcnew System::Windows::Forms::Button());
			this->btRESTART = (gcnew System::Windows::Forms::Button());
			this->tbPlayer1 = (gcnew System::Windows::Forms::TextBox());
			this->tbPlayer2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// Panel
			// 
			this->Panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Panel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->Panel->BackColor = System::Drawing::Color::Black;
			this->Panel->ColumnCount = 3;
			this->Panel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 31.63399F)));
			this->Panel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.29412F)));
			this->Panel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 32.94118F)));
			this->Panel->Controls->Add(this->btUpperLeft, 0, 0);
			this->Panel->Controls->Add(this->btUpper, 1, 0);
			this->Panel->Controls->Add(this->btUpperRight, 2, 0);
			this->Panel->Controls->Add(this->btLeft, 0, 1);
			this->Panel->Controls->Add(this->btCentr, 1, 1);
			this->Panel->Controls->Add(this->btRight, 2, 1);
			this->Panel->Controls->Add(this->btDownLeft, 0, 2);
			this->Panel->Controls->Add(this->btDown, 1, 2);
			this->Panel->Controls->Add(this->btDownRight, 2, 2);
			this->Panel->Location = System::Drawing::Point(0, 301);
			this->Panel->Name = L"Panel";
			this->Panel->RowCount = 3;
			this->Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 47.40883F)));
			this->Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 52.59117F)));
			this->Panel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 147)));
			this->Panel->Size = System::Drawing::Size(765, 459);
			this->Panel->TabIndex = 0;
			// 
			// btUpperLeft
			// 
			this->btUpperLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btUpperLeft->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btUpperLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btUpperLeft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btUpperLeft->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btUpperLeft->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btUpperLeft->Location = System::Drawing::Point(3, 3);
			this->btUpperLeft->Name = L"btUpperLeft";
			this->btUpperLeft->Size = System::Drawing::Size(236, 141);
			this->btUpperLeft->TabIndex = 0;
			this->btUpperLeft->UseVisualStyleBackColor = false;
			this->btUpperLeft->Click += gcnew System::EventHandler(this, &MainForm::btUpperLeft_Click);
			// 
			// btUpper
			// 
			this->btUpper->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btUpper->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btUpper->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btUpper->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btUpper->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btUpper->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btUpper->Location = System::Drawing::Point(245, 3);
			this->btUpper->Name = L"btUpper";
			this->btUpper->Size = System::Drawing::Size(264, 141);
			this->btUpper->TabIndex = 1;
			this->btUpper->UseVisualStyleBackColor = false;
			this->btUpper->Click += gcnew System::EventHandler(this, &MainForm::btUpper_Click);
			// 
			// btUpperRight
			// 
			this->btUpperRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btUpperRight->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btUpperRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btUpperRight->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btUpperRight->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btUpperRight->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btUpperRight->Location = System::Drawing::Point(515, 3);
			this->btUpperRight->Name = L"btUpperRight";
			this->btUpperRight->Size = System::Drawing::Size(247, 141);
			this->btUpperRight->TabIndex = 2;
			this->btUpperRight->UseVisualStyleBackColor = false;
			this->btUpperRight->Click += gcnew System::EventHandler(this, &MainForm::btUpperRight_Click);
			// 
			// btLeft
			// 
			this->btLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btLeft->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btLeft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btLeft->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btLeft->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btLeft->Location = System::Drawing::Point(3, 150);
			this->btLeft->Name = L"btLeft";
			this->btLeft->Size = System::Drawing::Size(236, 158);
			this->btLeft->TabIndex = 3;
			this->btLeft->UseVisualStyleBackColor = false;
			this->btLeft->Click += gcnew System::EventHandler(this, &MainForm::btLeft_Click);
			// 
			// btCentr
			// 
			this->btCentr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btCentr->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btCentr->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btCentr->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btCentr->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btCentr->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btCentr->Location = System::Drawing::Point(245, 150);
			this->btCentr->Name = L"btCentr";
			this->btCentr->Size = System::Drawing::Size(264, 158);
			this->btCentr->TabIndex = 4;
			this->btCentr->UseVisualStyleBackColor = false;
			this->btCentr->Click += gcnew System::EventHandler(this, &MainForm::btCentr_Click);
			// 
			// btRight
			// 
			this->btRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btRight->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btRight->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btRight->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btRight->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btRight->Location = System::Drawing::Point(515, 150);
			this->btRight->Name = L"btRight";
			this->btRight->Size = System::Drawing::Size(247, 158);
			this->btRight->TabIndex = 5;
			this->btRight->UseVisualStyleBackColor = false;
			this->btRight->Click += gcnew System::EventHandler(this, &MainForm::btRight_Click);
			// 
			// btDownLeft
			// 
			this->btDownLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btDownLeft->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btDownLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btDownLeft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btDownLeft->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btDownLeft->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btDownLeft->Location = System::Drawing::Point(3, 314);
			this->btDownLeft->Name = L"btDownLeft";
			this->btDownLeft->Size = System::Drawing::Size(236, 142);
			this->btDownLeft->TabIndex = 6;
			this->btDownLeft->UseVisualStyleBackColor = false;
			this->btDownLeft->Click += gcnew System::EventHandler(this, &MainForm::btDownLeft_Click);
			// 
			// btDown
			// 
			this->btDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btDown->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btDown->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btDown->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btDown->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btDown->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btDown->Location = System::Drawing::Point(245, 314);
			this->btDown->Name = L"btDown";
			this->btDown->Size = System::Drawing::Size(264, 142);
			this->btDown->TabIndex = 7;
			this->btDown->UseVisualStyleBackColor = false;
			this->btDown->Click += gcnew System::EventHandler(this, &MainForm::btDown_Click);
			// 
			// btDownRight
			// 
			this->btDownRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btDownRight->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btDownRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btDownRight->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btDownRight->Font = (gcnew System::Drawing::Font(L"Azeret Mono Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btDownRight->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btDownRight->Location = System::Drawing::Point(515, 314);
			this->btDownRight->Name = L"btDownRight";
			this->btDownRight->Size = System::Drawing::Size(247, 142);
			this->btDownRight->TabIndex = 8;
			this->btDownRight->UseVisualStyleBackColor = false;
			this->btDownRight->Click += gcnew System::EventHandler(this, &MainForm::btDownRight_Click);
			// 
			// lbnName
			// 
			this->lbnName->AutoSize = true;
			this->lbnName->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbnName->Location = System::Drawing::Point(323, 9);
			this->lbnName->Name = L"lbnName";
			this->lbnName->Size = System::Drawing::Size(94, 19);
			this->lbnName->TabIndex = 1;
			this->lbnName->Text = L"Tic-Tac-Toe";
			// 
			// lbMain
			// 
			this->lbMain->AutoSize = true;
			this->lbMain->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbMain->Location = System::Drawing::Point(97, 244);
			this->lbMain->Name = L"lbMain";
			this->lbMain->Size = System::Drawing::Size(18, 19);
			this->lbMain->TabIndex = 2;
			this->lbMain->Text = L"0";
			// 
			// btSTART
			// 
			this->btSTART->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btSTART->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->btSTART->Location = System::Drawing::Point(596, 161);
			this->btSTART->Name = L"btSTART";
			this->btSTART->Size = System::Drawing::Size(157, 50);
			this->btSTART->TabIndex = 3;
			this->btSTART->Text = L"START";
			this->btSTART->UseVisualStyleBackColor = true;
			this->btSTART->Click += gcnew System::EventHandler(this, &MainForm::btSTART_Click);
			// 
			// btRESTART
			// 
			this->btRESTART->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btRESTART->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->btRESTART->Location = System::Drawing::Point(596, 217);
			this->btRESTART->Name = L"btRESTART";
			this->btRESTART->Size = System::Drawing::Size(157, 50);
			this->btRESTART->TabIndex = 4;
			this->btRESTART->Text = L"RESTART";
			this->btRESTART->UseVisualStyleBackColor = true;
			this->btRESTART->Click += gcnew System::EventHandler(this, &MainForm::btRESTART_Click);
			// 
			// tbPlayer1
			// 
			this->tbPlayer1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPlayer1->Location = System::Drawing::Point(196, 73);
			this->tbPlayer1->Name = L"tbPlayer1";
			this->tbPlayer1->Size = System::Drawing::Size(167, 25);
			this->tbPlayer1->TabIndex = 5;
			// 
			// tbPlayer2
			// 
			this->tbPlayer2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPlayer2->ForeColor = System::Drawing::SystemColors::WindowText;
			this->tbPlayer2->Location = System::Drawing::Point(196, 108);
			this->tbPlayer2->Name = L"tbPlayer2";
			this->tbPlayer2->Size = System::Drawing::Size(167, 25);
			this->tbPlayer2->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->label1->Location = System::Drawing::Point(97, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 19);
			this->label1->TabIndex = 7;
			this->label1->Text = L"PLAYER1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
			this->label2->Location = System::Drawing::Point(97, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 19);
			this->label2->TabIndex = 8;
			this->label2->Text = L"PLAYER2";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(765, 760);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbPlayer2);
			this->Controls->Add(this->tbPlayer1);
			this->Controls->Add(this->btRESTART);
			this->Controls->Add(this->btSTART);
			this->Controls->Add(this->lbMain);
			this->Controls->Add(this->lbnName);
			this->Controls->Add(this->Panel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1920, 1080);
			this->MinimumSize = System::Drawing::Size(781, 783);
			this->Name = L"MainForm";
			this->Text = L"Tic-Tac-Toe";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//HideConsole();
		this->lbMain->Text = "Welcome! Choose your Player's names and press START!";
		
	}

	private: System::Void btSTART_Click(System::Object ^ sender, System::EventArgs ^ e) {
		
		if ((GameEnd != 1) && (moveNum < 1)) {
			frstMove = fcRand();
			ReadyGameStart();
			move = frstMove;

			if ((frstMove == 1) && (gameStart == 1))
			{
				this->lbMain->Text = "First move is for " + this->tbPlayer1->Text + " (X)";
				MoveNum();

				//this->lbMain->Text = " " + GameEnd + " " + gameStart + " " + moveNum;
			}
			else if ((frstMove == 2) && (gameStart == 1))
			{
				this->lbMain->Text = "First move is for " + this->tbPlayer2->Text + " (O)";
				MoveNum();

				//this->lbMain->Text = " " + GameEnd + " " + gameStart + " " + moveNum;
			}
			else
			{
				this->lbMain->Text = "Enter players names to play!";
			}
				
		}
		else if ((gameStart == 1) && (stopper == 0)) {
			
			this->lbMain->Text = this->lbMain->Text + " (Press RESTART to reset the field)";
			stopper++;
		}

		
		

	}
	private: System::Void btUpperLeft_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		
		ReadyGameStart();
		GameResult();
		//this->lbMain->Text = " " + GameEnd + " " + gameStart + " " + moveNum;
		if ((moveNum <9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btUpperLeft->Text == "") {
				if (move == 1) {
					this->btUpperLeft->Text = "X";
					GameArr[0][0] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btUpperLeft->Text = "O";
					GameArr[0][0] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btUpperLeft->Text == "") {
				if (move == 1) {
					this->btUpperLeft->Text = "X";
					GameArr[0][0] = 1;
					move = nxtMove(move);
				}
				else if (move == 2) {
					this->btUpperLeft->Text = "O";
					GameArr[0][0] = 2;
					move = nxtMove(move);
				}
			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if (GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}

	}
	private: System::Void btUpper_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btUpper->Text == "") {
				if (move == 1) {
					this->btUpper->Text = "X";
					GameArr[0][1] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btUpper->Text = "O";
					GameArr[0][1] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btUpper->Text == "") {
				if (move == 1) {
					this->btUpper->Text = "X";
					GameArr[0][1] = 1;
					move = nxtMove(move);
				}
				else if (move == 2) {
					this->btUpper->Text = "O";
					GameArr[0][1] = 2;
					move = nxtMove(move);
				}
				moveNum = MoveNum();
			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if (GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}
	private: System::Void btUpperRight_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btUpperRight->Text == "") {
				if (move == 1) {
					this->btUpperRight->Text = "X";
					GameArr[0][2] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btUpperRight->Text = "O";
					GameArr[0][2] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			move = nxtMove(move);
			if (this->btUpperRight->Text == "") {
				if (move == 1) {
					this->btUpperRight->Text = "X";
					GameArr[0][2] = 1;
				}
				else if (move == 2) {
					this->btUpperRight->Text = "O";
					GameArr[0][2] = 2;
				}
				moveNum = MoveNum();
			}
			else {

			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if (GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1) 
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}
	private: System::Void btLeft_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btLeft->Text == "") {
				if (move == 1) {
					this->btLeft->Text = "X";
					GameArr[1][0] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btLeft->Text = "O";
					GameArr[1][0] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			move = nxtMove(move);
			if (this->btLeft->Text == "") {
				if (move == 1) {
					this->btLeft->Text = "X";
					GameArr[1][0] = 1;
				}
				else if (move == 2) {
					this->btLeft->Text = "O";
					GameArr[1][0] = 2;
				}
				moveNum = MoveNum();
			}
			else {

			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if(GameWinner == 1)
			this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if(GameWinner == 2)
			this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
			this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}
	private: System::Void btCentr_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btCentr->Text == "") {
				if (move == 1) {
					this->btCentr->Text = "X";
					GameArr[1][1] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btCentr->Text = "O";
					GameArr[1][1] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			move = nxtMove(move);
			if (this->btCentr->Text == "") {
				if (move == 1) {
					this->btCentr->Text = "X";
					GameArr[1][1] = 1;
				}
				else if (move == 2) {
					this->btCentr->Text = "O";
					GameArr[1][1] = 2;
				}
				moveNum = MoveNum();
			}
			else {

			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if (GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}
	private: System::Void btRight_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btRight->Text == "") {
				if (move == 1) {
					this->btRight->Text = "X";
					GameArr[1][2] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btRight->Text = "O";
					GameArr[1][2] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			move = nxtMove(move);
			if (this->btRight->Text == "") {
				if (move == 1) {
					this->btRight->Text = "X";
					GameArr[1][2] = 1;
				}
				else if (move == 2) {
					this->btRight->Text = "O";
					GameArr[1][2] = 2;
				}
				moveNum = MoveNum();
			}
			else {

			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if (GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}
	private: System::Void btDownLeft_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btDownLeft->Text == "") {
				if (move == 1) {
					this->btDownLeft->Text = "X";
					GameArr[2][0] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btDownLeft->Text = "O";
					GameArr[2][0] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			move = nxtMove(move);
			if (this->btDownLeft->Text == "") {
				if (move == 1) {
					this->btDownLeft->Text = "X";
					GameArr[2][0] = 1;
				}
				else if (move == 2) {
					this->btDownLeft->Text = "O";
					GameArr[2][0] = 2;
				}
				moveNum = MoveNum();
			}
			else {

			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if (GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}
	private: System::Void btDown_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btDown->Text == "") {
				if (move == 1) {
					this->btDown->Text = "X";
					GameArr[2][1] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btDown->Text = "O";
					GameArr[2][1] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			move = nxtMove(move);
			if (this->btDown->Text == "") {
				if (move == 1) {
					this->btDown->Text = "X";
					GameArr[2][1] = 1;
				}
				else if (move == 2) {
					this->btDown->Text = "O";
					GameArr[2][1] = 2;
				}
				moveNum = MoveNum();
			}
			else {

			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if (GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}
	private: System::Void btDownRight_Click(System::Object ^ sender, System::EventArgs ^ e) {
		ReadyGameStart();
		
		GameResult();
		if ((moveNum < 9) && (gameStart == 1) && (GameEnd == 0)) {
			if (this->btDownRight->Text == "") {
				if (move == 1) {
					this->btDownRight->Text = "X";
					GameArr[2][2] = 1;
					move = nxtMove(move);
					stopper = 0;
				}
				else if (move == 2) {
					this->btDownRight->Text = "O";
					GameArr[2][2] = 2;
					move = nxtMove(move);
					stopper = 0;
				}
				MoveNum();
			}
			else {

			}
		}
		/*else if ((moveNum > 0) && (gameStart == 1) && (GameEnd == 0)) {
			move = nxtMove(move);
			if (this->btDownRight->Text == "") {
				if (move == 1) {
					this->btDownRight->Text = "X";
					GameArr[2][2] = 1;
				}
				else if (move == 2) {
					this->btDownRight->Text = "O";
					GameArr[2][2] = 2;
				}
				moveNum = MoveNum();
			}
			else {

			}
		}*/
		
		GameResult();
		if (GameEnd == 1) {
			if		(GameWinner == 1)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer1->Text + " win!";
			else if (GameWinner == 2)
				this->lbMain->Text = "GAME OVER! " + this->tbPlayer2->Text + " win!";
			else if (GameDraw == 1)
				this->lbMain->Text = "GAME OVER! DRAW!";
			
		}
	}

private: System::Void btRESTART_Click(System::Object^ sender, System::EventArgs^ e) {
	
	NamingVar();
	
	this->btUpperLeft->Text = "";
	this->btUpper->Text = "";
	this->btUpperRight->Text = "";
	this->btLeft->Text = "";
	this->btCentr->Text = "";
	this->btRight->Text = "";
	this->btDownLeft->Text = "";
	this->btDown->Text = "";
	this->btDownRight->Text = "";

	ClearArr();

	this->lbMain->Text = "You can change names. Press START to play!";
	//this->lbMain->Text = " " + GameEnd + " " + gameStart + " " + moveNum;
}
};
}
