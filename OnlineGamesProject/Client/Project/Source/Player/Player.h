#pragma once

#include "DxLib.h"
#include "../Memory/Memory.h"
#include "../Component/Transform.h"

class Splite;
class Controller2D;

class Player
{

public:
	Player();
	~Player();

	void Init();
	void Load();
	void Start();
	virtual void Step();
	virtual void Draw();

	//アクセサ
	void SetPos(const VECTOR& pos) { m_Transform.SetPos(pos); }
	void SetPos(const VECTOR& rot) { m_Transform.SetPos(rot); }
	void SetPos(const VECTOR& scale) { m_Transform.SetPos(scale); }

protected:
	float m_MoveSpeed;
	float m_ScaleSpeed;
	float m_RotSpeed;
	Transform m_Transform;
	UniquePtr<Splite> m_Splite;
	UniquePtr<Controller2D> m_Controller;
};
