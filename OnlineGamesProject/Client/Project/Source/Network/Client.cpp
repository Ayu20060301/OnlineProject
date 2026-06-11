#include "DxLib.h"
#include "../Input/Input.h"
#include "Client.h"
#include "NetworkCommonParam.h"
#include "../Input/InputString.h"

Client::Client()
{
	//初期化
	m_PartnerHandle = 0;
	m_NWState = NW_STATE_NONE;
	m_IPAddress = {};
	m_NameInput = nullptr;
	m_MessageInput = nullptr;
	m_SendChatData = {};
	m_ChatData = {};

}

Client::~Client()
{
	
}


void Client::Init()
{
	//キー文字列入力設定
	m_NameInput = MakeUnique<InputString>();
	m_MessageInput = MakeUnique<InputString>();

	m_NameInput->SetPos(VGet(0.0f, 20.0f, 0.0f));
	m_MessageInput->SetPos(VGet(0.0f, 20.0f, 0.0f));

	//最初は名前入力
	m_NameInput->Start();
	m_NWState = NW_STATE_INPUT_NAME;
}

void Client::Update()
{
	switch (m_NWState)
	{
	case NW_STATE_INPUT_NAME: break;
	case NW_STATE_WAITING: break;
	case NW_STATE_INPUT_MESSAGE: break;
	}
}

void Client::Draw()
{
	if (m_NWState == NW_STATE_INPUT_NAME)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "ユーザー名を入力");
	}
	else if (m_NWState == NW_STATE_WAITING)
	{

	}
	else if (m_NWState == NW_STATE_INPUT_MESSAGE)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "メッセージを入力");
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Ctrl + Qで切断");
		DrawFormatString(0, 0, GetColor(255, 255, 255), "接続先IPアドレス : %d%d%d%d", m_IPAddress.d1,m_IPAddress.d2,m_IPAddress.d3,m_IPAddress.d4);
	}

	m_NameInput->Draw();
	m_MessageInput->Draw();

}

void Client::Fin()
{
	//状態が接続中移行であれば切断
	if (m_NWState >= NW_STATE_WAITING)
	{

	}
}

void Client::Connect()
{

}
