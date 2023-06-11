#pragma once
#include <frc/controller/PIDController.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/Filesystem.h>
#include <frc/filter/SlewRateLimiter.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/RunCommand.h>
#include "subsystems/ClimberSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/PickUpSubsystem.h"
#include "Constants.h"
#include <memory>
#include <pathplanner/lib/PathPlanner.h>
#include <wpi/fs.h>
#include <frc/DataLogManager.h>
#include <wpi/DataLog.h>
#include <frc/PowerDistribution.h>
#include "commands/PickUpCycle.h"
#include "commands/PickUpCycleBounce.h"
#include "subsystems/NewPickupSubsystem.h"
#include "subsystems/ArmSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

class RobotContainer {
public:

	RobotContainer();

	void LogData();

	wpi::log::DataLog& m_log;

	DriveSubsystem m_drive;
	//PickUpSubsystem m_pickUp;
	//ClimberSubsystem m_climber;
	NewPickupSubsystem m_newPickup;
	frc::PowerDistribution m_powerDistributionPanel;
	ArmSubsystem m_arm;
	

private:

	frc2::RunCommand m_driveCommand;

	frc::XboxController m_driverController{OIConstants::kDriverControllerPort};
	frc::XboxController m_climberController{OIConstants::kClimberControllerPort};

	// The robot's subsystems
	frc::SlewRateLimiter<units::scalar> m_xspeedLimiter{.5 / 1_s};
	frc::SlewRateLimiter<units::scalar> m_yspeedLimiter{.5 / 1_s};
	frc::SlewRateLimiter<units::scalar> m_rotLimiter{6 / 1_s};
	frc::SlewRateLimiter<units::scalar> m_powerLimiter{1. / 1_s};

	frc2::JoystickButton *m_rb;
	frc2::JoystickButton *m_lb;

	void _ConfigureButtonBindings();

	//bool IsNearWaypoint(Pose2d waypoint, double within);

	wpi::log::DoubleLogEntry m_totalCurrent;
	wpi::log::DoubleLogEntry m_batteryVoltage;

	PickUpCycle* m_pickUpCycleCommand;
	PickUpCycleBounce* m_pickUpCycleBounceCommand;
};
