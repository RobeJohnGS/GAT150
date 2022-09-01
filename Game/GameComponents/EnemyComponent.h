#pragma once
#include "Components/CharacterComponent.h"

class EnemyComponent : public JREngine::CharacterComponent {
	CLASS_DECLARATION(EnemyComponent)

	virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(JREngine::Actor* other) override;
	virtual void OnCollisionExit(JREngine::Actor* other) override;

	virtual void OnNotify(const JREngine::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;
};