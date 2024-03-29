// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/geometry/Translation2d.h>
#include <frc/kinematics/SwerveDriveKinematics.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <units/constants.h>


/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

// ==========================================================================

namespace DriveConstants {
	constexpr int kFrontLeftDriveMotorPort = 22;
	constexpr int kRearLeftDriveMotorPort = 24;
	constexpr int kFrontRightDriveMotorPort = 28;
	constexpr int kRearRightDriveMotorPort = 26;

	constexpr int kFrontLeftTurningMotorPort = 21;
	constexpr int kRearLeftTurningMotorPort = 23;
	constexpr int kFrontRightTurningMotorPort = 27;
	constexpr int kRearRightTurningMotorPort = 25;

	constexpr int kFrontLeftPot = 1;
	constexpr int kFrontRightPot = 4;
	constexpr int kRearLeftPot = 2;
	constexpr int kRearRightPot = 3;

	//constexpr double driveMaxVoltage = 12;
	constexpr double driveMaxVoltage = 10;
	//constexpr double driveMaxVoltage = 8;

	//TurningPIDConstants
	//constexpr auto kts = .1_V;
	//constexpr auto ktv = .24_V/(1_rad_per_s);
	//constexpr auto ktv = .33_V/(1_rad_per_s);
	//constexpr auto kta = 0;

	// Example value only - as above, this must be tuned for your drive!
	//constexpr double kPFrontLeftVel = 0.5;
	// constexpr double kPRearLeftVel = 0.5;
	// constexpr double kPFrontRightVel = 0.5;
	// constexpr double kPRearRightVel = 0.5;

	constexpr double stickDeadBand = .1;

	constexpr auto kMaxSpeed = units::meters_per_second_t(4);
	constexpr auto kMaxAngularSpeed = units::radians_per_second_t(2 * std::numbers::pi); 
} // namespace DriveConstants

// ==========================================================================

namespace ModuleConstants {
	//constexpr int kEncoderCPR = 1024;
	//constexpr double kWheelDiameterMeters = 0.1143 * 0.93; //0.1143 was working with worn wheels 
	//constexpr double kDriveEncoderDistancePerPulse =
	// Assumes the encoders are directly mounted on the wheel shafts
	//(kWheelDiameterMeters * std::numbers::pi) /
	//static_cast<double>(kEncoderCPR);

	//stexpr double kTurningEncoderDistancePerPulse =
	// Assumes the encoders are directly mounted on the wheel shafts
	//(std::numbers::pi * 2) / static_cast<double>(kEncoderCPR);

	constexpr double kPModuleTurningController = 1. / std::numbers::pi;
	constexpr double kPSwerveModuleTurningController = 2. / std::numbers::pi;
	constexpr double kPModuleDriveController = .2; //0.025; //15mar23 0.5
	constexpr double kmaxTurnOutput = .5;

	//DrivePIDConstants
	constexpr auto ks = .64705_V;
	//constexpr auto kv = 2.5 * 1_V * 1_s / 1_m;
	//constexpr auto kv = 3.07 * 1_V * 1_s / 1_m;   
	constexpr auto kv = 2.2489 * 1_V * 1_s / 1_m;
	constexpr auto ka = .26974 * 1_V * 1_s * 1_s / 1_m;

	//constexpr double kPModuleTurningController = 0.45;
	//constexpr double kPModuleDriveController = 0.025;
} // namespace ModuleConstants

// ==========================================================================

namespace AutoConstants {
	using radians_per_second_squared_t =
		units::compound_unit<units::radians,
		units::inverse<units::squared<units::second>>>;

	constexpr auto kMaxSpeed = units::meters_per_second_t(3);
	constexpr auto kMaxAcceleration = units::meters_per_second_squared_t(3);
	constexpr auto kMaxAngularSpeed = units::radians_per_second_t(2 * std::numbers::pi); 
	constexpr auto kMaxAngularAcceleration = units::unit_t<radians_per_second_squared_t>(std::numbers::pi);

	constexpr double kPXController = 1.;  //0.5
	constexpr double kPYController = 1.;  //0.5
	constexpr double kPThetaController = 5.0;

	extern const frc::TrapezoidProfile<units::radians>::Constraints kThetaControllerConstraints;
}

// ==========================================================================

namespace OIConstants {
	constexpr int kDriverControllerPort = 0;
	constexpr int kClimberControllerPort = 1;
}

// ==========================================================================

namespace PickUpConstants {
	constexpr int kRollerPort = 31;
	constexpr int kIndex1Port = 32;
	constexpr int kIndex2Port = 33;

	constexpr int kShooter1Port = 34;
	constexpr int kShooter2Port = 35;
	constexpr int kBackSpinShooterPort = 36;

	constexpr int kShooterForwardSolenoidPort = 4;
	constexpr int kShooterReverseSolenoidPort = 2;

	constexpr int kUpperForwardSolenoidPort = 5;
	constexpr int kUpperReverseSolenoidPort = 1;
	constexpr int kLowerForwardSolenoidPort = 0;
	constexpr int kLowerReverseSolenoidPort = 6;

	constexpr double kShortSpeed = 0.6;
	constexpr double kLongSpeed = 0.475;
	constexpr double kShortSpeedSlow = 0.35;
	constexpr double kLongSpeedSlow = 0.4;
}

// ==========================================================================

namespace ClimberConstants {
	constexpr int kRotateLeftPort = 42;
	constexpr int kRotateRightPort = 41;
	constexpr int kExtendLeftPort = 44;
	constexpr int kExtendRightPort = 43;

	constexpr int kBrakeSolenoidPortRght = 3;
	constexpr int kBrakeSolenoidPortLeft = 7;


	//constexpr float kMaxExtendPower = .6;
	//constexpr float kMaxRotatePower = .3;

	constexpr double kPR = .025; //5e-4; 
	constexpr double kIR = 1e-5;    //1e-6; 
	constexpr double kDR = 1;  //0
	constexpr double kIzR = 0; 
	constexpr double kFFR = 0; 
	constexpr double kMaxOutputR = 0.5;
	constexpr double kMinOutputR = -0.5;

	constexpr double kPE = 5e-6; //5e-4; 
	constexpr double kIE = 1e-6;    //1e-6; 
	constexpr double kDE = 0;  //0
	constexpr double kIzE = 0; 
	constexpr double kFFE = 0.000156; 
	constexpr double kMaxOutputE = 1.0;
	constexpr double kMinOutputE = -1.0;


	constexpr double kMaxVel = 5500; 
	constexpr double kMinVel = 0; 
	constexpr double kMaxAcc = 5000; 
	constexpr double kAllErr = 0;
	constexpr double MaxRPM = 5700;
}

// ==========================================================================
