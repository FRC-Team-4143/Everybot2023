// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/RunCommand.h>


/*frc2::CommandPtr autos::SimpleAuto(DriveSubsystem* drive, ArmSubsystem* arm) {
  return frc2::FunctionalCommand(
             // Reset encoders on command start
             [drive] { drive->ResetEncoders(); },
             // Drive forward while the command is executing
             [drive] { drive->ArcadeDrive(AutoConstants::kAutoDriveSpeed, 0); },
             // Stop driving at the end of the command
             [drive](bool interrupted) { drive->ArcadeDrive(0, 0); },
             // End the command when the robot's driven distance exceeds the
             // desired value
             [drive] {
               return drive->GetAverageEncoderDistance() >=
                      AutoConstants::kAutoDriveDistanceInches;
             },
             // Requires the drive subsystem
             {drive})
      .ToPtr();
}*/

frc2::CommandPtr autos::SimpleAuto(DriveSubsystem* m_drive,
                                    ArmSubsystem* m_arm,
                                    NewPickupSubsystem* m_newPickup) {
  return frc2::cmd::Sequence(
      frc2::FunctionalCommand(
		[m_arm]() {m_arm->autoArmCount=0;},
		[m_arm, m_newPickup]() {m_arm->setArmMotor(-.215); m_newPickup->autoOut(m_arm->isArmOut());m_arm->autoArmCount++;},
		[m_arm](bool) { m_arm->setArmMotor(0); },
		[m_arm]() {return (m_arm->autoArmCount > 250);},
        {m_arm, m_newPickup}).ToPtr(),
        frc2::RunCommand(
		[m_drive](){m_drive->Drive(-1_mps,0_mps,units::radians_per_second_t(0));},{m_drive}).ToPtr().WithTimeout(3_s)
  ); 
}


