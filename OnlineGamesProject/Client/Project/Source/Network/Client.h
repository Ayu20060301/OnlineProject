#pragma once
#include "DxLib.h"
#include "NetworkCommonParam.h"

class InputString;

// ゲームの状態
enum NetworkGameState
{
	GAME_STATE_OFFLINE,	// オフライン中
	GAME_STATE_ONLINE,	// オンライン中
};

// 通信の状態
enum NetworkState
{
	NW_STATE_DISCONNECT,			// 切断している
	NW_STATE_WAITING_CONNECTION,	// 接続中
	NW_STATE_CONNECT,				// 接続している
};

class Client
{
public:
	Client();
	~Client();

public:
	void Init();
	void Update();
	void Draw();
	void Fin();

	void Connect();
	void Disconnect();

public:

	void UpdateDisconnect();
	void UpdateWaitingConnection();
	void UpdateConnect();

public:
	void SetIPAddress(IPDATA address) { m_IPAddress = address; }

	NetworkGameState GetNetworkGameState() const { return m_NWGameState; }
	NetworkState GetNetworkState() const { return m_NWState; }


private:
	int m_ServerHandle;
	NetworkGameState m_NWGameState;
	NetworkState m_NWState;
	IPDATA m_IPAddress;
	InputString* m_UserNameInput;
	InputString* m_MessageInput;

	//送信するチャットデータ
	ChatData m_ChatData;

};

