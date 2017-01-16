#pragma once

#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>
#include<iostream>

#include"SingleTon.h"

#include"GraphicMgr.h"
#include"TextureMgr.h"
#include"SceneMgr.h"
#include"InputMgr.h"
#include"GameMgr.h"
#include"GameObject.h"
#include"Timer.h"
#include"GameTime.h"
#include"AnimationSprite.h"
#include"PlayerMgr.h"
#include"Sprite.h"
#define SAFE_DELETE(x) { if(x) { delete x; x = NULL; } }
#define SAFE_RELEASE(x) { if(x) { x->Release(); x = NULL; } }