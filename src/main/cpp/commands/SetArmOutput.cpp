#include "commands/SetArmOutput.h"

// SetArmOutput::SetArmOutput(ArmSubsystem* subsystem, double initPercentOutput) 
// : m_arm(subsystem)
// {
//     percentOutput = initPercentOutput;
// 	AddRequirements(subsystem);
// }

// void SetArmOutput::Initialize() {
	
	
// }

// void SetArmOutput::Execute() {
// 	m_arm->setArmMotor(percentOutput);
// }

// void SetArmOutput::End(bool) {
// 	m_arm->setArmMotor(0);
// }

bool SetArmOutput::IsFinished() {
	return true;
}