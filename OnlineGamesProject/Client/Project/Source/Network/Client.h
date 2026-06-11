#pragma once
#include "DxLib.h"
#include "NetworkCommonParam.h"
#include "../Memory/Memory.h"
#include <vector>

class InputString;

// 通信の状態
enum NetworkState
{
	NW_STATE_NONE,
	NW_STATE_INPUT_NAME, //ユーザー名入力中
	NW_STATE_WAITING,   //接続待ち
	NW_STATE_INPUT_MESSAGE   //メッセージ入力中
};

class Client
{
public:
	Client();
	virtual ~Client();

public:
	void Init();
	void Update();
	void Draw();
	void Fin();

	void SetIPAddress(IPDATA address) { m_IPAddress = address; }

public:

	//ホスト/クライアント処理
	void UpdateInputName();
	void UpdateInputMessage();
	void ReceiveData();
	void DrawChat();
	void Connect();
	void Dosconnect();

	//ホスト/クライアントで別々の処理
	virtual void StartNetwork();
	virtual void UpdateWaiting();
	virtual void DrawWaiting();

private:
	int m_PartnerHandle;
	ChatData m_SendChatData;
	NetworkState m_NWState;
	IPDATA m_IPAddress;
	UniquePtr<InputString> m_NameInput;
	UniquePtr<InputString> m_MessageInput;
	std::vector<ChatData> m_ChatData;
};
