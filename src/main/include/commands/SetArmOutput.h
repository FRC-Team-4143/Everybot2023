#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ArmSubsystem.h"

class SetArmOutput : public frc2::CommandHelper<frc2::CommandBase, SetArmOutput> {
public:

	
    explicit SetArmOutput(ArmSubsystem* subsystem, double initPercentOutput);
	void Initialize() override;
    void Execute() override;
    void End(bool) override;
	bool IsFinished() override;
	bool RunsWhenDisabled() const override;

private:
    double percentOutput;
	ArmSubsystem* m_arm;
};

