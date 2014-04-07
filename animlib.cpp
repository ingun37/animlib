#define OSMac_

#include "animlib.h"
#include <maya/MSimple.h>
#include <maya/MIOStream.h>

#define OSMac_
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#include <maya/MIOStream.h>
#include <maya/MFStream.h>

#include "animImportExportStrings.h"

#include <maya/MGlobal.h>
#include <maya/MString.h>

#include <maya/MFnAnimCurve.h>
#include <maya/MAnimCurveClipboard.h>
#include <maya/MAnimCurveClipboardItem.h>
#include <maya/MAnimCurveClipboardItemArray.h>

#if defined (OSMac_)
using namespace std;
#endif










//-------------------------------------------------------------------------
//	Class animUnitNames
//-------------------------------------------------------------------------

//	String names for units.
//
const char *kMmString = 		"mm";
const char *kCmString =			"cm";
const char *kMString =			"m";
const char *kKmString =			"km";
const char *kInString =			"in";
const char *kFtString =			"ft";
const char *kYdString =			"yd";
const char *kMiString =			"mi";

const char *kMmLString =		"millimeter";
const char *kCmLString =		"centimeter";
const char *kMLString =			"meter";
const char *kKmLString =		"kilometer";
const char *kInLString =		"inch";
const char *kFtLString =		"foot";
const char *kYdLString =		"yard";
const char *kMiLString =		"mile";

const char *kRadString =		"rad";
const char *kDegString =		"deg";
const char *kMinString =		"min";
const char *kSecString =		"sec";

const char *kRadLString =		"radian";
const char *kDegLString =		"degree";
const char *kMinLString =		"minute";
const char *kSecLString =		"second";

const char *kHourTString =		"hour";
const char *kMinTString =		"min";
const char *kSecTString =		"sec";
const char *kMillisecTString =	"millisec";

const char *kGameTString =		"game";
const char *kFileTString =		"film";
const char *kPalTString =		"pal";
const char *kNtscTString =		"ntsc";
const char *kShowTString =		"show";
const char *kPalFTString =		"palf";
const char *kNtscFTString =		"ntscf";

const char *kUnitlessString = "unitless";
const char *kUnknownTimeString =	"Unknown Time Unit";
const char *kUnknownAngularString =	"Unknown Angular Unit";
const char *kUnknownLinearString = 	"Unknown Linear Unit";

animUnitNames::animUnitNames()
//
//	Description:
//		Class constructor.
//
{
}

animUnitNames::~animUnitNames()
//
//	Description:
//		Class destructor.
//
{
}

/* static */
void animUnitNames::setToLongName(const MAngle::Unit& unit, MString& name)
//
//	Description:
//		Sets the string with the long text name of the angle unit.
//
{
		switch(unit) {
				case MAngle::kDegrees:
				name.set(kDegLString);
				break;
				case MAngle::kRadians:
				name.set(kRadLString);
				break;
				case MAngle::kAngMinutes:
				name.set(kMinLString);
				break;
				case MAngle::kAngSeconds:
				name.set(kSecLString);
				break;
				default:
				name.set(kUnknownAngularString);
				break;
		}
}

/* static */
void animUnitNames::setToShortName(const MAngle::Unit& unit, MString& name)
//
//	Description:
//		Sets the string with the short text name of the angle unit.
//
{
		switch(unit) {
				case MAngle::kDegrees:
				name.set(kDegString);
				break;
				case MAngle::kRadians:
				name.set(kRadString);
				break;
				case MAngle::kAngMinutes:
				name.set(kMinString);
				break;
				case MAngle::kAngSeconds:
				name.set(kSecString);
				break;
				default:
				name.set(kUnknownAngularString);
				break;
		}
}

/* static */
void animUnitNames::setToLongName(const MDistance::Unit& unit, MString& name)
//
//	Description:
//		Sets the string with the long text name of the distance unit.
//
{
		switch(unit) {
				case MDistance::kInches:
				name.set(kInLString);
				break;
				case MDistance::kFeet:
				name.set(kFtLString);
				break;
				case MDistance::kYards:
				name.set(kYdLString);
				break;
				case MDistance::kMiles:
				name.set(kMiLString);
				break;
				case MDistance::kMillimeters:
				name.set(kMmLString);
				break;
				case MDistance::kCentimeters:
				name.set(kCmLString);
				break;
				case MDistance::kKilometers:
				name.set(kKmLString);
				break;
				case MDistance::kMeters:
				name.set(kMLString);
				break;
				default:
				name.set(kUnknownLinearString);
				break;
		}
}

/* static */
void animUnitNames::setToShortName(const MDistance::Unit& unit, MString& name)
//
//	Description:
//		Sets the string with the short text name of the distance unit.
//
{
		switch(unit) {
				case MDistance::kInches:
				name.set(kInString);
				break;
				case MDistance::kFeet:
				name.set(kFtString);
				break;
				case MDistance::kYards:
				name.set(kYdString);
				break;
				case MDistance::kMiles:
				name.set(kMiString);
				break;
				case MDistance::kMillimeters:
				name.set(kMmString);
				break;
				case MDistance::kCentimeters:
				name.set(kCmString);
				break;
				case MDistance::kKilometers:
				name.set(kKmString);
				break;
				case MDistance::kMeters:
				name.set(kMString);
				break;
				default:
				name.set(kUnknownLinearString);
				break;
		}
}

/* static */
void animUnitNames::setToLongName(const MTime::Unit &unit, MString &name)
//
//	Description:
//		Sets the string with the long text name of the time unit.
//
{
		switch(unit) {
				case MTime::kHours:
				name.set(kHourTString);
				break;
				case MTime::kMinutes:
				name.set(kMinTString);
				break;
				case MTime::kSeconds:
				name.set(kSecTString);
				break;
				case MTime::kMilliseconds:
				name.set(kMillisecTString);
				break;
				case MTime::kGames:
				name.set(kGameTString);
				break;
				case MTime::kFilm:
				name.set(kFileTString);
				break;
				case MTime::kPALFrame:
				name.set(kPalTString);
				break;
				case MTime::kNTSCFrame:
				name.set(kNtscTString);
				break;
				case MTime::kShowScan:
				name.set(kShowTString);
				break;
				case MTime::kPALField:
				name.set(kPalFTString);
				break;
				case MTime::kNTSCField:
				name.set(kNtscFTString);
				break;
				default:
				name.set(kUnknownTimeString);
				break;
		}
}

/* static */
void animUnitNames::setToShortName(const MTime::Unit &unit, MString &name)
//
//	Description:
//		Sets the string with the short text name of the time unit.
//
{
		setToLongName(unit, name);
}

/* static */
bool animUnitNames::setFromName(const MString &str, MAngle::Unit &unit)
//
//	Description:
//		The angle unit is set based on the passed string. If the string
//		is not recognized, the angle unit is set to MAngle::kInvalid.
//
{
		bool state = true;
		
		const char *name = str.asChar();
		
		if ((strcmp(name, kDegString) == 0) ||
			(strcmp(name, kDegLString) == 0)) {
				unit = MAngle::kDegrees;
		} else if (	(strcmp(name, kRadString) == 0) ||
				   (strcmp(name, kRadLString) == 0)) {
				unit = MAngle::kRadians;
		} else if (	(strcmp(name, kMinString) == 0) ||
				   (strcmp(name, kMinLString) == 0)) {
				unit = MAngle::kAngMinutes;
		} else if (	(strcmp(name, kSecString) == 0) ||
				   (strcmp(name, kSecLString) == 0)) {
				unit = MAngle::kAngSeconds;
		} else {
				//	This is not a recognized angular unit.
				//
				unit = MAngle::kInvalid;
				MStatus stat;
				MString msg;
				// Use format to place variable string into message
				MString msgFmt = MStringResource::getString(kInvalidAngleUnits, stat);
				msg.format(msgFmt, str);
				MGlobal::displayError(msg);
				state = false;
		}
		
		return state;
}

/* static */
bool animUnitNames::setFromName(const MString &str, MDistance::Unit &unit)
//
//	Description:
//		The distance unit is set based on the passed string. If the string
//		is not recognized, the distance unit is set to MDistance::kInvalid.
//
{
		bool state = true;
		
		const char *name = str.asChar();
		
		if ((strcmp(name, kInString) == 0) ||
			(strcmp(name, kInLString) == 0)) {
				unit = MDistance::kInches;
		} else if (	(strcmp(name, kFtString) == 0) ||
				   (strcmp(name, kFtLString) == 0)) {
				unit = MDistance::kFeet;
		} else if (	(strcmp(name, kYdString) == 0) ||
				   (strcmp(name, kYdLString) == 0)) {
				unit = MDistance::kYards;
		} else if (	(strcmp(name, kMiString) == 0) ||
				   (strcmp(name, kMiLString) == 0)) {
				unit = MDistance::kMiles;
		} else if (	(strcmp(name, kMmString) == 0) ||
				   (strcmp(name, kMmLString) == 0)) {
				unit = MDistance::kMillimeters;
		} else if (	(strcmp(name, kCmString) == 0) ||
				   (strcmp(name, kCmLString) == 0)) {
				unit = MDistance::kCentimeters;
		} else if (	(strcmp(name, kKmString) == 0) ||
				   (strcmp(name, kKmLString) == 0)) {
				unit = MDistance::kKilometers;
		} else if (	(strcmp(name, kMString) == 0) ||
				   (strcmp(name, kMLString) == 0)) {
				unit = MDistance::kMeters;
		} else {
				//  This is not a recognized distance unit.
				//
				state = false;
				MStatus stat;
				MString msg;
				// Use format to place variable string into message
				MString msgFmt = MStringResource::getString(kInvalidLinearUnits, stat);
				msg.format(msgFmt, str);
				MGlobal::displayError(msg);
				unit = MDistance::kInvalid;
		}
		
		return state;
}

/* static */
bool animUnitNames::setFromName(const MString &str, MTime::Unit &unit)
//
//	Description:
//		The time unit is set based on the passed string. If the string
//		is not recognized, the time unit is set to MTime::kInvalid.
//
{
		bool state = true;
		const char *name = str.asChar();
		
		if (strcmp(name, kHourTString) == 0) {
				unit = MTime::kHours;
		} else if (strcmp(name, kMinTString) == 0) {
				unit = MTime::kMinutes;
		} else if (strcmp(name, kSecTString) == 0) {
				unit = MTime::kSeconds;
		} else if (strcmp(name, kMillisecTString) == 0) {
				unit = MTime::kMilliseconds;
		} else if (strcmp(name, kGameTString) == 0) {
				unit = MTime::kGames;
		} else if (strcmp(name, kFileTString) == 0) {
				unit = MTime::kFilm;
		} else if (strcmp(name, kPalTString) == 0) {
				unit = MTime::kPALFrame;
		} else if (strcmp(name, kNtscTString) == 0) {
				unit = MTime::kNTSCFrame;
		} else if (strcmp(name, kShowTString) == 0) {
				unit = MTime::kShowScan;
		} else if (strcmp(name, kPalFTString) == 0) {
				unit = MTime::kPALField;
		} else if (strcmp(name, kNtscFTString) == 0) {
				unit = MTime::kNTSCField;
		} else {
				//  This is not a recognized time unit.
				//
				unit = MTime::kInvalid;
				MStatus stat;
				MString msg;
				// Use format to place variable string into message
				MString msgFmt = MStringResource::getString(kInvalidTimeUnits, stat);
				msg.format(msgFmt, str);
				MGlobal::displayError(msg);
				state = false;
		}
		
		return state;
}

//-------------------------------------------------------------------------
//	Class animBase
//-------------------------------------------------------------------------

// Tangent type words
//
const char *kWordTangentGlobal = "global";
const char *kWordTangentFixed = "fixed";
const char *kWordTangentLinear = "linear";
const char *kWordTangentFlat = "flat";
const char *kWordTangentSmooth = "spline";
const char *kWordTangentStep = "step";
const char *kWordTangentSlow = "slow";
const char *kWordTangentFast = "fast";
const char *kWordTangentClamped = "clamped";
const char *kWordTangentPlateau = "plateau";
const char *kWordTangentStepNext = "stepnext";
const char *kWordTangentAuto = "auto";

// Infinity type words
//
const char *kWordConstant = "constant";
const char *kWordLinear = "linear";
const char *kWordCycle = "cycle";
const char *kWordCycleRelative = "cycleRelative";
const char *kWordOscillate = "oscillate";

//	Param Curve types
//
const char *kWordTypeUnknown = "unknown";
const char *kWordTypeLinear = "linear";
const char *kWordTypeAngular = "angular";
const char *kWordTypeTime = "time";
const char *kWordTypeUnitless = "unitless";

//	Keywords
//
const char *kAnim = "anim";
const char *kAnimData = "animData";
const char *kMovData = "movData";
const char *kMayaVersion = "mayaVersion";
const char *kAnimVersion = "animVersion";

const char *kTimeUnit = "timeUnit";
const char *kLinearUnit = "linearUnit";
const char *kAngularUnit = "angularUnit";
const char *kStartTime = "startTime";
const char *kEndTime = "endTime";
const char *kStartUnitless = "startUnitless";
const char *kEndUnitless = "endUnitless";

// animVersions:
//
const char *kAnimVersionString = "1.1";
// const double kVersion1 = 1.0;						// initial release
const double kVersionNonWeightedAndBreakdowns = 1.1;	// added support for non-weighted curves and breakdowns

const char *kTwoSpace = "  ";

//	animData keywords
//
const char *kInputString = "input";
const char *kOutputString = "output";
const char *kWeightedString = "weighted";
const char *kPreInfinityString = "preInfinity";
const char *kPostInfinityString = "postInfinity";
const char *kInputUnitString = "inputUnit";
const char *kOutputUnitString = "outputUnit";
const char *kTanAngleUnitString = "tangentAngleUnit";
const char *kKeysString = "keys";

//	special characters
//
const char kSemiColonChar	= ';';
const char kSpaceChar		= ' ';
const char kTabChar			= '\t';
const char kHashChar		= '#';
const char kNewLineChar		= '\n';
const char kSlashChar		= '/';
const char kBraceLeftChar	= '{';
const char kBraceRightChar	= '}';
const char kDoubleQuoteChar	= '"';

animBase::animBase ()
//
//	Description:
//		The constructor.
//
{
		resetUnits();
}

animBase::~animBase()
//
//	Description:
//		The destructor.
//
{
}

void animBase::resetUnits()
//
//	Description:
//		Reset the units used by this class to the ui units.
//
{
		timeUnit = MTime::uiUnit();
		linearUnit = MDistance::uiUnit();
		angularUnit = MAngle::uiUnit();
}

const char *
animBase::tangentTypeAsWord(MFnAnimCurve::TangentType type)
//
//	Description:
//		Returns a string with a test based desription of the passed
//		MFnAnimCurve::TangentType.
//
{
		switch (type) {
				case MFnAnimCurve::kTangentGlobal:
				return (kWordTangentGlobal);
				case MFnAnimCurve::kTangentFixed:
				return (kWordTangentFixed);
				case MFnAnimCurve::kTangentLinear:
				return (kWordTangentLinear);
				case MFnAnimCurve::kTangentFlat:
				return (kWordTangentFlat);
				case MFnAnimCurve::kTangentSmooth:
				return (kWordTangentSmooth);
				case MFnAnimCurve::kTangentStep:
				return (kWordTangentStep);
				case MFnAnimCurve::kTangentStepNext:
				return (kWordTangentStepNext);
				case MFnAnimCurve::kTangentSlow:
				return (kWordTangentSlow);
				case MFnAnimCurve::kTangentFast:
				return (kWordTangentFast);
				case MFnAnimCurve::kTangentClamped:
				return (kWordTangentClamped);
				case MFnAnimCurve::kTangentPlateau:
				return (kWordTangentPlateau);
				case MFnAnimCurve::kTangentAuto:
				return (kWordTangentAuto);
				default:
				break;
		}
		return (kWordTangentGlobal);
}

MFnAnimCurve::TangentType
animBase::wordAsTangentType (char *type)
//
//	Description:
//		Returns a MFnAnimCurve::TangentType based on the passed string.
//		If the string is not a recognized tangent type, tnen
//		MFnAnimCurve::kTangentGlobal is returned.
//
{
		if (strcmp(type, kWordTangentGlobal) == 0) {
				return (MFnAnimCurve::kTangentGlobal);
		}
		if (strcmp(type, kWordTangentFixed) == 0) {
				return (MFnAnimCurve::kTangentFixed);
		}
		if (strcmp(type, kWordTangentLinear) == 0) {
				return (MFnAnimCurve::kTangentLinear);
		}
		if (strcmp(type, kWordTangentFlat) == 0) {
				return (MFnAnimCurve::kTangentFlat);
		}
		if (strcmp(type, kWordTangentSmooth) == 0) {
				return (MFnAnimCurve::kTangentSmooth);
		}
		if (strcmp(type, kWordTangentStep) == 0) {
				return (MFnAnimCurve::kTangentStep);
		}
		if (strcmp(type, kWordTangentStepNext) == 0) {
				return (MFnAnimCurve::kTangentStepNext);
		}
		if (strcmp(type, kWordTangentSlow) == 0) {
				return (MFnAnimCurve::kTangentSlow);
		}
		if (strcmp(type, kWordTangentFast) == 0) {
				return (MFnAnimCurve::kTangentFast);
		}
		if (strcmp(type, kWordTangentClamped) == 0) {
				return (MFnAnimCurve::kTangentClamped);
		}
		if (strcmp(type, kWordTangentPlateau) == 0) {
				return (MFnAnimCurve::kTangentPlateau);
		}
		if (strcmp(type, kWordTangentAuto) == 0) {
				return (MFnAnimCurve::kTangentAuto);
		}
		return (MFnAnimCurve::kTangentGlobal);
}

const char *
animBase::infinityTypeAsWord(MFnAnimCurve::InfinityType type)
//
//	Description:
//		Returns a string containing the name of the passed
//		MFnAnimCurve::InfinityType type.
//
{
		switch (type) {
				case MFnAnimCurve::kConstant:
				return (kWordConstant);
				case MFnAnimCurve::kLinear:
				return (kWordLinear);
				case MFnAnimCurve::kCycle:
				return (kWordCycle);
				case MFnAnimCurve::kCycleRelative:
				return (kWordCycleRelative);
				case MFnAnimCurve::kOscillate:
				return (kWordOscillate);
				default:
				break;
		}
		return (kWordConstant);
}

MFnAnimCurve::InfinityType
animBase::wordAsInfinityType(const char *type)
//
//	Description:
//		Returns a MFnAnimCurve::InfinityType from the passed string.
//		If the string does not match a recognized infinity type,
//		MFnAnimCurve::kConstant is returned.
//
{
		if (strcmp(type, kWordConstant) == 0) {
				return(MFnAnimCurve::kConstant);
		} else if (strcmp(type, kWordLinear) == 0) {
				return (MFnAnimCurve::kLinear);
		} else if (strcmp(type, kWordCycle) == 0) {
				return (MFnAnimCurve::kCycle);
		} else if (strcmp(type, kWordCycleRelative) == 0) {
				return (MFnAnimCurve::kCycleRelative);
		} else if (strcmp(type, kWordOscillate) == 0) {
				return (MFnAnimCurve::kOscillate);
		}
		
		return (MFnAnimCurve::kConstant);
}

const char *
animBase::outputTypeAsWord (MFnAnimCurve::AnimCurveType type)
//
//	Description:
//		Returns a string identifying the output type of the
//		passed MFnAnimCurve::AnimCurveType.
//
{
		switch (type) {
				case MFnAnimCurve::kAnimCurveTL:
				case MFnAnimCurve::kAnimCurveUL:
				return (kWordTypeLinear);
				case MFnAnimCurve::kAnimCurveTA:
				case MFnAnimCurve::kAnimCurveUA:
				return (kWordTypeAngular);
				case MFnAnimCurve::kAnimCurveTT:
				case MFnAnimCurve::kAnimCurveUT:
				return (kWordTypeTime);
				case MFnAnimCurve::kAnimCurveTU:
				case MFnAnimCurve::kAnimCurveUU:
				return (kWordTypeUnitless);
				case MFnAnimCurve::kAnimCurveUnknown:
				return (kWordTypeUnitless);
		}
		return (kWordTypeUnknown);
}

animBase::AnimBaseType
animBase::wordAsInputType(const char *input)
//
//	Description:
//		Returns an input type based on the passed string.
//
{
		if (strcmp(input, kWordTypeTime) == 0) {
				return animBase::kAnimBaseTime;
		} else {
				return animBase::kAnimBaseUnitless;
		}
}

animBase::AnimBaseType
animBase::wordAsOutputType(const char *output)
//
//	Description:
//		Returns a output type based on the passed string.
//
{
		if (strcmp(output, kWordTypeLinear) == 0) {
				return animBase::kAnimBaseLinear;
		} else if (strcmp(output, kWordTypeAngular) == 0) {
				return animBase::kAnimBaseAngular;
		} else if (strcmp(output, kWordTypeTime) == 0) {
				return animBase::kAnimBaseTime;
		} else {
				return animBase::kAnimBaseUnitless;
		}
}

const char *
animBase::boolInputTypeAsWord(bool isUnitless)
//
//	Description:
//		Returns a string based on a bool.
//
{
		if (isUnitless) {
				return (kWordTypeUnitless);
		} else {
				return (kWordTypeTime);
		}
}


MFnAnimCurve::AnimCurveType
animBase::typeAsAnimCurveType(	animBase::AnimBaseType input,
							  animBase::AnimBaseType output)
//
//	Description:
//		Returns a MFnAnimCurve::AnimCurveType based on the passed
//		input and output types. If the input and output types do
//		not create a valid MFnAnimCurve::AnimCurveType, then a
//		MFnAnimCurve::kAnimCurveUnknown is returned.
//
{
		MFnAnimCurve::AnimCurveType type = MFnAnimCurve::kAnimCurveUnknown;
		
		switch (output) {
				case kAnimBaseLinear:
				if (kAnimBaseUnitless == input) {
						type = MFnAnimCurve::kAnimCurveUL;
				} else {
						type = MFnAnimCurve::kAnimCurveTL;
				}
				break;
				case kAnimBaseAngular:
				if (kAnimBaseUnitless == input) {
						type = MFnAnimCurve::kAnimCurveUA;
				} else {
						type = MFnAnimCurve::kAnimCurveTA;
				}
				break;
				case kAnimBaseTime:
				if (kAnimBaseUnitless == input) {
						type = MFnAnimCurve::kAnimCurveUT;
				} else {
						type = MFnAnimCurve::kAnimCurveTT;
				}
				break;
				case kAnimBaseUnitless:
				if (kAnimBaseUnitless == input) {
						type = MFnAnimCurve::kAnimCurveUU;
				} else {
						type = MFnAnimCurve::kAnimCurveTU;
				}
				break;
				default:
				//	An unknown anim curve type.
				//
				break;
		}
		
		return type;
}

double animBase::asDouble (ifstream &clipFile)
//
//	Description:
//		Reads the next bit of valid data as a double.
//
{
		advance(clipFile);
		
		double value;
		clipFile >> value;
		
		return (value);
}

bool animBase::isNextNumeric(ifstream &clipFile)
//
//	Description:
//		The method skips past whitespace and comments and checks if
//		the next character is numeric.
//
//		true is returned if the character is numeric.
//
{
		bool numeric = false;
		advance(clipFile);
		
		char next = clipFile.peek();
		if (next >= '0' && next <= '9') {
				numeric = true;
		}
		
		return numeric;
}

void animBase::advance (ifstream &clipFile)
//
//	Description:
//		The method skips past all of the whitespace and commented lines
//		in the ifstream. It will also ignore semi-colons.
//
{
		while (clipFile) {
				clipFile >> ws;
				
				char next = clipFile.peek();
				
				if (next == kSemiColonChar) {
						clipFile.ignore(1, kSemiColonChar);
						continue;
				}
				
				if (next == kSlashChar || next == kHashChar) {
						clipFile.ignore(INT_MAX, kNewLineChar);
						continue;
				}
				
				break;
		}
}

char* animBase::asWord (ifstream &clipFile, bool includeWS /* false */)
//
//	Description:
//		Returns the next string of characters in an ifstream. The string
//		ends when whitespace or a semi-colon is encountered. If the
//		includeWS argument is true, the string will not end if a white
//		space character is encountered.
//
//		If a double quote is detected '"', then verything up to the next
//		double quote will be returned.
//
//		This method returns a pointer to a static variable, so its contents
//		should be used immediately.
//
{
		static const int kBufLength = 1024;
		static char string[kBufLength];
		
		advance(clipFile);
		
		char *c = string;
		clipFile.read (c, 1);
		
		if (*c == kDoubleQuoteChar) {
				clipFile.read(c, 1);
				while(!clipFile.eof() && (*c != kDoubleQuoteChar)) {
						c++;
						if (c-string >= kBufLength) {
								break;
						}
						clipFile.read(c, 1);
				}
		} else {
				
				//	Get the case of the '{' or '}' character
				//
				if (*c == kBraceLeftChar || *c == kBraceRightChar) {
						c++;
				} else {
						while(!clipFile.eof() && (*c != kSemiColonChar)) {
								if (!includeWS && ((*c == kSpaceChar) || (*c == kTabChar))) {
										break;
								}
								c++;
								if (c-string >= kBufLength) {
										break;
								}
								clipFile.read(c, 1);
						}
				}
		}
		*c = 0x00;
		
		return (string);
}

char animBase::asChar (ifstream &clipFile)
//
//	Description:
//		Returns the next character of interest in the ifstream. All
//		whitespace and commented lines are ignored.
//
{
		advance(clipFile);
		return clipFile.get();
}

bool animBase::isEquivalent(double a, double b)
//
//	Description:
//		Returns true if the doubles are within the tolerance.
//
{
		const double tolerance = 1.0e-10;
		return ((a > b) ? (a - b <= tolerance) : (b - a <= tolerance));
}

//-----------------------------------------------------------------------------
//	Class animReader
//-----------------------------------------------------------------------------

animReader::animReader ()
//
//	Description:
//		Class constructor.
//
:	animVersion (1.0)
,	convertAnglesFromV2To3(false)
,	convertAnglesFromV3To2(false)
{
}

animReader::~animReader()
//
//	Description:
//		Class destructor.
//
{
}

MStatus
animReader::readClipboard(ifstream &readAnim, MAnimCurveClipboard& cb)
//
//	Description:
//		Given a clipboard and an ifstream, read the ifstream and add
//		all of the anim curves described in ther stream into the
//		API clipboard.
//
{
		//	Set the default values for the start and end of the clipboard.
		//	The MAnimCurveClipboard::set() method will examine all of the
		//	anim curves are determine the proper start and end values, if the
		//	start time is greater than the end value.
		//
		//	By default, the start values are greater than the end values to
		//	ensure correct behavior if the file does not specify the start and
		//	end values.
		//
		//
		double startTime = 1.0;
		double endTime = 0.0;
		double startUnitless = 1.0;
		double endUnitless = 0.0;
		
		resetUnits();
		convertAnglesFromV2To3 = false;
		convertAnglesFromV3To2 = false;
		
		//	Read the header. The header officially ends when the first non-header
		//	keyword is found. The header contains clipboard specific information
		//	where the body is anim curve specific.
		//
		char *dataType = NULL;
		bool hasVersionString = false;
		while (!readAnim.eof()) {
				advance(readAnim);
				dataType = asWord(readAnim);
				
				if (strcmp(dataType, kAnimVersion) == 0) {
						MString version(asWord(readAnim));
						animVersion = version.asDouble();
						MString thisVersion(kAnimVersionString);
						
						hasVersionString = true;
						
						//	Add versioning control here.
						//
						if (version != thisVersion) {
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kInvalidVersion,
																			stat);
								msg.format(msgFmt, version, thisVersion);
								MGlobal::displayWarning(msg);
						}
				} else if (strcmp(dataType, kMayaVersion) == 0) {
						MString version(asWord(readAnim, true));
						
						MString currentVersion = MGlobal::mayaVersion();
						if (currentVersion.substring(0,1) == "2.") {
								MString vCheck = version.substring(0, 1);
								if (vCheck != "2.") {
										convertAnglesFromV3To2 = true;
								}
						} else {
								//	If this is a pre-Maya 3.0 file, then the tangent angles
								//	will need to be converted to work in Maya 3.0+
								//
								MString vCheck = version.substring(0, 1);
								if (vCheck == "2.") {
										convertAnglesFromV2To3 = true;
								}
						}
				} else if (strcmp(dataType, kTimeUnit) == 0) {
						MString timeUnitString(asWord(readAnim));
						if (!animUnitNames::setFromName(timeUnitString, timeUnit)) {
								MString unitName;
								timeUnit = MTime::uiUnit();
								animUnitNames::setToShortName(timeUnit, unitName);
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kSettingToUnit,
																			stat);
								msg.format(msgFmt, kTimeUnit, unitName);
								MGlobal::displayWarning(msg);
						}
				} else if (strcmp(dataType, kLinearUnit) == 0) {
						MString linearUnitString(asWord(readAnim));
						if (!animUnitNames::setFromName(linearUnitString, linearUnit)) {
								MString unitName;
								linearUnit = MDistance::uiUnit();
								animUnitNames::setToShortName(linearUnit, unitName);
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kSettingToUnit,
																			stat);
								msg.format(msgFmt, kLinearUnit, unitName);
								MGlobal::displayWarning(msg);
						}
				} else if (strcmp(dataType, kAngularUnit) == 0) {
						MString angularUnitString(asWord(readAnim));
						if (!animUnitNames::setFromName(angularUnitString, angularUnit)) {
								MString unitName;
								angularUnit = MAngle::uiUnit();
								animUnitNames::setToShortName(angularUnit, unitName);
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kSettingToUnit,
																			stat);
								msg.format(msgFmt, kAngularUnit, unitName);
								MGlobal::displayWarning(msg);
						}
				} else if (strcmp(dataType, kStartTime) == 0) {
						startTime = asDouble(readAnim);
				} else if (strcmp(dataType, kEndTime) == 0) {
						endTime = asDouble(readAnim);
				} else if (strcmp(dataType, kStartUnitless) == 0) {
						startUnitless = asDouble(readAnim);
				} else if (strcmp(dataType, kEndUnitless) == 0) {
						endUnitless = asDouble(readAnim);
				} else {
						//	The header should be finished. Begin to parse the body.
						//
						break;
				}
		}
		
		//	The animVersion string is required.
		//
		if (!hasVersionString) {
				MStatus stat;
				MString msg;
				// Use format to place variable string into message
				MString msgFmt = MStringResource::getString(kMissingKeyword, stat);
				msg.format(msgFmt, kAnimVersion);
				MGlobal::displayError(msg);
				return (MS::kFailure);
		}
		
		//	Set the linear and angular units to be the same as the file
		//	being read. This will allow fixed tangent data to be read
		//	in properly if the scene has different units than the .anim file.
		//
		MDistance::Unit oldDistanceUnit = MDistance::uiUnit();
		MTime::Unit oldTimeUnit = MTime::uiUnit();
		
		MDistance::setUIUnit(linearUnit);
		MTime::setUIUnit(timeUnit);
		
		MAnimCurveClipboardItemArray clipboardArray;
		while (!readAnim.eof()) {
				
				if (NULL == dataType) {
						dataType = asWord(readAnim);
				}
				
				if (strcmp(dataType, kAnim) == 0) {
						MString fullAttributeName, leafAttributeName, nodeName;
						
						//	If this is from an unconnected anim curve, then there
						//	will not be an attribute name.
						//
						if (!isNextNumeric(readAnim)) {
								fullAttributeName.set(asWord(readAnim));
								
								//	If the node names were specified, then the next two
								//	words should be the leaf attribute and the node name.
								//
								if (!isNextNumeric(readAnim)) {
										leafAttributeName.set(asWord(readAnim));
										nodeName.set(asWord(readAnim));
								}
						}
						
						unsigned rowCount, childCount, attrCount;
						rowCount = (unsigned)asDouble(readAnim);
						childCount = (unsigned)asDouble(readAnim);
						attrCount = (unsigned)asDouble(readAnim);
						
						//	If the next keyword is not an animData, then this is
						//	a place holder for the API clipboard.
						//
						dataType = asWord(readAnim);
						if (strcmp(dataType, kAnimData) == 0) {
								MAnimCurveClipboardItem clipboardItem;
								if (readAnimCurve(readAnim, clipboardItem)) {
										clipboardItem.setAddressingInfo(rowCount,
																		childCount, attrCount);
										clipboardItem.setNameInfo(	nodeName,
																  fullAttributeName,
																  leafAttributeName);
										clipboardArray.append(clipboardItem);
								} else {
										//	Could not read the anim curve.
										//
										MStatus stringStat;
										MString msg = MStringResource::getString(kCouldNotReadAnim,
																				 stringStat);
										MGlobal::displayError(msg);
								}
						} else {
								//	This must be a place holder object for the clipboard.
								//
								MAnimCurveClipboardItem clipboardItem;
								clipboardItem.setAddressingInfo(rowCount,
																childCount, attrCount);
								
								//	Since there is no anim curve specified, what is
								//	in the fullAttributeName string is really the node
								//	name.
								//
								clipboardItem.setNameInfo(	fullAttributeName,
														  nodeName,
														  leafAttributeName);
								clipboardArray.append(clipboardItem);
								
								//	dataType already contains the next keyword.
								//
								continue;
						}
				} else {
						if (!readAnim.eof()) {
								MString warnStr(dataType);
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kUnknownKeyword,
																			stat);
								msg.format(msgFmt, warnStr);
								MGlobal::displayError(msg);
								
								//	Skip to the next line, this one is invalid.
								//
								readAnim.ignore(INT_MAX, kNewLineChar);
						} else {
								//	The end of the file was reached.
								//
								break;
						}
				}
				
				//	Skip any whitespace.
				//
				dataType = NULL;
		}
		
		if (MS::kSuccess != cb.set(	clipboardArray,
								   MTime(startTime, timeUnit), MTime(endTime, timeUnit),
								   (float) startUnitless, (float) endUnitless)) {
				
				MStatus stringStat;
				MString msg = MStringResource::getString(kClipboardFailure,
														 stringStat);
				MGlobal::displayError(msg);
		}
		
		//	Restore the old units.
		//
		MDistance::setUIUnit(oldDistanceUnit);
		MTime::setUIUnit(oldTimeUnit);
		
		return (MS::kSuccess);
}

void animReader::convertAnglesAndWeights3To2(MFnAnimCurve::AnimCurveType type,
											 bool isWeighted, MAngle &angle, double &weight)
//
//	Description:
//		Converts the tangent angles from Maya 3.0 to Maya2.* formats.
//
{
		double oldAngle = angle.as(MAngle::kRadians);
		double newAngle = oldAngle;
		
		//	Calculate the scale values for the conversion.
		//
		double xScale = 1.0;
		double yScale = 1.0;
		
		MTime tOne(1.0, MTime::kSeconds);
		if (type == MFnAnimCurve::kAnimCurveTT ||
			type == MFnAnimCurve::kAnimCurveTL ||
			type == MFnAnimCurve::kAnimCurveTA ||
			type == MFnAnimCurve::kAnimCurveTU) {
				
				xScale = tOne.as(MTime::uiUnit());
		}
		
		switch (type) {
				case MFnAnimCurve::kAnimCurveTT:
				case MFnAnimCurve::kAnimCurveUT:
				yScale = tOne.as(MTime::uiUnit());
				break;
				case MFnAnimCurve::kAnimCurveTL:
				case MFnAnimCurve::kAnimCurveUL:
				{
						MDistance dOne(1.0, MDistance::internalUnit());
						yScale = dOne.as(linearUnit);
				}
				break;
				case MFnAnimCurve::kAnimCurveTA:
				case MFnAnimCurve::kAnimCurveUA:
				{
						MAngle aOne(1.0, MAngle::internalUnit());
						yScale = aOne.as(angularUnit);
				}
				break;
				case MFnAnimCurve::kAnimCurveTU:
				case MFnAnimCurve::kAnimCurveUU:
				default:
				break;
		}
		
		double tanAngle = tan(oldAngle);
		newAngle = atan((xScale*tanAngle)/yScale);
		
		if (isWeighted) {
				double sinAngle = sin(oldAngle);
				double cosAngle = cos(oldAngle);
				
				double denominator = (yScale*yScale*sinAngle*sinAngle) +
				(xScale*xScale*cosAngle*cosAngle);
				weight = sqrtl(weight/denominator);
		}
		
		MAngle finalAngle(newAngle, MAngle::kRadians);
		angle = finalAngle;
}

void animReader::convertAnglesAndWeights2To3(MFnAnimCurve::AnimCurveType type,
											 bool isWeighted, MAngle &angle, double &weight)
//
//	Description:
//		Converts the tangent angles from Maya 2.* to Maya3.0+ formats.
//
{
		double oldAngle = angle.as(MAngle::kRadians);
		
		double newAngle = oldAngle;
		double newWeight = weight;
		
		//	Calculate the scale values for the conversion.
		//
		double xScale = 1.0;
		double yScale = 1.0;
		
		MTime tOne(1.0, MTime::kSeconds);
		if (type == MFnAnimCurve::kAnimCurveTT ||
			type == MFnAnimCurve::kAnimCurveTL ||
			type == MFnAnimCurve::kAnimCurveTA ||
			type == MFnAnimCurve::kAnimCurveTU) {
				
				xScale = tOne.as(MTime::uiUnit());
		}
		
		switch (type) {
				case MFnAnimCurve::kAnimCurveTT:
				case MFnAnimCurve::kAnimCurveUT:
				yScale = tOne.as(MTime::uiUnit());
				break;
				case MFnAnimCurve::kAnimCurveTL:
				case MFnAnimCurve::kAnimCurveUL:
				{
						MDistance dOne(1.0, MDistance::internalUnit());
						yScale = dOne.as(linearUnit);
				}
				break;
				case MFnAnimCurve::kAnimCurveTA:
				case MFnAnimCurve::kAnimCurveUA:
				{
						MAngle aOne(1.0, MAngle::internalUnit());
						yScale = aOne.as(angularUnit);
				}
				break;
				case MFnAnimCurve::kAnimCurveTU:
				case MFnAnimCurve::kAnimCurveUU:
				default:
				break;
		}
		
		const double quarter = M_PI/2;
		if (isEquivalent(oldAngle, 0.0) ||
			isEquivalent(oldAngle, quarter) ||
			isEquivalent(oldAngle, -quarter)) {
				
				newAngle = oldAngle;
				
				if (isWeighted) {
						newWeight = yScale*oldAngle;
				}
		} else {
				double tanAngle = tan(oldAngle);
				newAngle = atan((yScale*tanAngle)/xScale);
				
				if (isWeighted) {
						double cosAngle = cos(oldAngle);
						double cosSq = cosAngle*cosAngle;
						
						double wSq = (weight*weight) *
						(((xScale*xScale - yScale*yScale)*cosSq) + (yScale*yScale));
						
						newWeight = sqrtl(wSq);
				}
		}
		
		weight = newWeight;
		
		MAngle finalAngle(newAngle, MAngle::kRadians);
		angle = finalAngle;
}

bool animReader::readAnimCurve(
							   ifstream &clipFile, MAnimCurveClipboardItem &item)
//
//	Description:
//		Read a block of the ifstream that should contain anim curve
//		data in the format determined by the animData keyword.
//
{
		MFnAnimCurve animCurve;
		MObject animCurveObj;
		
		//	Anim curve defaults.
		//
		animBase::AnimBaseType input = wordAsInputType(kWordTypeTime);
		animBase::AnimBaseType output = wordAsOutputType(kWordTypeLinear);
		MFnAnimCurve::InfinityType preInf = wordAsInfinityType(kWordConstant);
		MFnAnimCurve::InfinityType postInf = wordAsInfinityType(kWordConstant);
		
		MString inputUnitName;
		animUnitNames::setToShortName(timeUnit, inputUnitName);
		MString outputUnitName;
		MAngle::Unit tanAngleUnit = angularUnit;
		bool isWeighted (false);
		
		char *dataType;
		while (!clipFile.eof()) {
				advance(clipFile);
				
				dataType = asWord(clipFile);
				
				if (strcmp(dataType, kInputString) == 0) {
						input = wordAsInputType(asWord(clipFile));
				} else if (strcmp(dataType, kOutputString) == 0) {
						output = wordAsOutputType(asWord(clipFile));
				} else if (strcmp(dataType, kWeightedString) == 0) {
						isWeighted = (asDouble(clipFile) == 1.0);
				} else if (strcmp(dataType, kPreInfinityString) == 0) {
						preInf = wordAsInfinityType(asWord(clipFile));
				} else if (strcmp(dataType, kPostInfinityString) == 0) {
						postInf = wordAsInfinityType(asWord(clipFile));
				} else if (strcmp(dataType, kInputUnitString) == 0) {
						inputUnitName.set(asWord(clipFile));
				} else if (strcmp(dataType, kOutputUnitString) == 0) {
						outputUnitName.set(asWord(clipFile));
				} else if (strcmp(dataType, kTanAngleUnitString) == 0) {
						MString tUnit(asWord(clipFile));
						if (!animUnitNames::setFromName(tUnit, tanAngleUnit)) {
								MString unitName;
								tanAngleUnit = angularUnit;
								animUnitNames::setToShortName(tanAngleUnit, unitName);
								
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kSettingTanAngleUnit, stat);
								msg.format(msgFmt, unitName);
								MGlobal::displayError(msg);
						}
				} else if (strcmp(dataType, kKeysString) == 0) {
						//	Ignore the rest of this line.
						//
						clipFile.ignore(INT_MAX, kNewLineChar);
						break;
				} else if (strcmp(dataType, "{") == 0) {
						//	Skippping the '{' character. Just ignore it.
						//
						continue;
				} else {
						//	An unrecogized keyword was found.
						//
						MString warnStr(dataType);
						MStatus stat;
						MString msg;
						// Use format to place variable string into message
						MString msgFmt = MStringResource::getString(kUnknownKeyword,
																	stat);
						msg.format(msgFmt, warnStr);
						MGlobal::displayError(msg);
						continue;
				}
		}
		
		// Read the animCurve
		//
		MStatus status;
		MFnAnimCurve::AnimCurveType type = typeAsAnimCurveType(input, output);
		animCurveObj = animCurve.create(type, NULL, &status);
		
		if (status != MS::kSuccess) {
				MString msg = MStringResource::getString(kCouldNotCreateAnim, status);
				MGlobal::displayError(msg);
				return false;
		}
		
		animCurve.setIsWeighted(isWeighted);
		animCurve.setPreInfinityType(preInf);
		animCurve.setPostInfinityType(postInf);
		
		//	Set the appropriate units.
		//
		MTime::Unit inputTimeUnit;
		if (input == kAnimBaseTime) {
				if (!animUnitNames::setFromName(inputUnitName, inputTimeUnit)) {
						MString unitName;
						inputTimeUnit = timeUnit;
						animUnitNames::setToShortName(inputTimeUnit, unitName);
						MStatus stat;
						MString msg;
						// Use format to place variable string into message
						MString msgFmt = MStringResource::getString(kSettingToUnit,
																	stat);
						msg.format(msgFmt, kInputUnitString, unitName);
						MGlobal::displayWarning(msg);
				}
		}
		
		MTime::Unit outputTimeUnit;
		if (output == kAnimBaseTime) {
				if (!animUnitNames::setFromName(outputUnitName, outputTimeUnit)) {
						MString unitName;
						outputTimeUnit = timeUnit;
						animUnitNames::setToShortName(outputTimeUnit, unitName);
						MStatus stat;
						MString msg;
						// Use format to place variable string into message
						MString msgFmt = MStringResource::getString(kSettingToUnit,
																	stat);
						msg.format(msgFmt, kOutputUnitString, unitName);
						MGlobal::displayWarning(msg);
				}
		}
		
		int index = 0;
		double conversion = 1.0;
		if (output == kAnimBaseLinear) {
				MDistance::Unit unit;
				if (outputUnitName.length() != 0) {
						if (!animUnitNames::setFromName(outputUnitName, unit)) {
								MString unitName;
								unit = linearUnit;
								animUnitNames::setToShortName(unit, unitName);
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kSettingToUnit,
																			stat);
								msg.format(msgFmt, kOutputUnitString, unitName);
								MGlobal::displayWarning(msg);
						}
				} else {
						unit = linearUnit;
				}
				if (unit != MDistance::kCentimeters) {
						MDistance one(1.0, unit);
						conversion = one.as(MDistance::kCentimeters);
				}
		} else if (output == kAnimBaseAngular) {
				MAngle::Unit unit;
				if (outputUnitName.length() != 0) {
						if (!animUnitNames::setFromName(outputUnitName, unit)) {
								MString unitName;
								unit = angularUnit;
								animUnitNames::setToShortName(unit, unitName);
								MStatus stat;
								MString msg;
								// Use format to place variable string into message
								MString msgFmt = MStringResource::getString(kSettingToUnit,
																			stat);
								msg.format(msgFmt, kOutputUnitString, unitName);
								MGlobal::displayWarning(msg);
						}
				} else {
						unit = angularUnit;
				}
				if (unit != MAngle::kRadians) {
						MAngle one(1.0, unit);
						conversion = one.as(MAngle::kRadians);
				}
		}
		
		// Now read each keyframe
		//
		advance(clipFile);
		char c = clipFile.peek();
		while (clipFile && c != kBraceRightChar) {
				double t = asDouble (clipFile);
				double val = asDouble (clipFile);
				
				MFnAnimCurve::TangentType tanIn = wordAsTangentType(asWord(clipFile));
				MFnAnimCurve::TangentType tanOut = wordAsTangentType(asWord(clipFile));
				
				switch (type) {
						case MFnAnimCurve::kAnimCurveTT:
						index = animCurve.addKey(	MTime(val, inputTimeUnit),
												 MTime(val, outputTimeUnit),
												 tanIn, tanOut, NULL, &status);
						break;
						case MFnAnimCurve::kAnimCurveTL:
						case MFnAnimCurve::kAnimCurveTA:
						case MFnAnimCurve::kAnimCurveTU:
						index = animCurve.addKey(	MTime(t, inputTimeUnit),
												 val*conversion, tanIn, tanOut,
												 NULL, &status);
						break;
						case MFnAnimCurve::kAnimCurveUL:
						case MFnAnimCurve::kAnimCurveUA:
						case MFnAnimCurve::kAnimCurveUU:
						index = animCurve.addKey(	t, val*conversion,
												 tanIn, tanOut,
												 NULL, &status);
						break;
						case MFnAnimCurve::kAnimCurveUT:
						index = animCurve.addKey(	t, MTime(val, outputTimeUnit),
												 tanIn, tanOut,
												 NULL, &status);
						break;
						default:
						MString msg = MStringResource::getString(kUnknownNode, status);
						MGlobal::displayError(msg);
						return false;
				}
				
				if (status != MS::kSuccess) {
						MStatus stringStat;
						MString msg = MStringResource::getString(kCouldNotKey, stringStat);
						MGlobal::displayError(msg);
				}
				
				//	Tangent locking needs to be called after the weights and
				//	angles are set for the fixed tangents.
				//
				bool tLocked = bool(asDouble(clipFile) == 1.0);
				bool swLocked = bool(asDouble(clipFile) == 1.0);
				bool isBreakdown (false);
				if (animVersion >= kVersionNonWeightedAndBreakdowns) {
						isBreakdown = (asDouble(clipFile) == 1.0);
				}
				
				//	Only fixed tangents need additional information.
				//
				if (tanIn == MFnAnimCurve::kTangentFixed) {
						MAngle inAngle(asDouble(clipFile), tanAngleUnit);
						double inWeight = asDouble(clipFile);
						
						//	If this is from a pre-Maya3.0 file, the tangent angles will
						//	need to be converted.
						//
						if (convertAnglesFromV2To3) {
								convertAnglesAndWeights2To3(type,isWeighted,inAngle,inWeight);
						} else if (convertAnglesFromV3To2) {
								convertAnglesAndWeights3To2(type,isWeighted,inAngle,inWeight);
						}
						
						//  By default, the tangents are locked. When the tangents
						//	are locked, setting the angle and weight of a fixed in
						//	tangent may change the tangent type of the out tangent.
						//
						animCurve.setTangentsLocked(index, false);
						animCurve.setTangent(index, inAngle, inWeight, true);
				}
				
				//	Only fixed tangents need additional information.
				//
				if (tanOut == MFnAnimCurve::kTangentFixed) {
						MAngle outAngle(asDouble(clipFile), tanAngleUnit);
						double outWeight = asDouble(clipFile);
						
						//	If this is from a pre-Maya3.0 file, the tangent angles will
						//	need to be converted.
						//
						if (convertAnglesFromV2To3) {
								convertAnglesAndWeights2To3(type,isWeighted,outAngle,outWeight);
						} else if (convertAnglesFromV3To2) {
								convertAnglesAndWeights3To2(type,isWeighted,outAngle,outWeight);
						}
						
						//  By default, the tangents are locked. When the tangents
						//	are locked, setting the angle and weight of a fixed out
						//	tangent may change the tangent type of the in tangent.
						//
						animCurve.setTangentsLocked(index, false);
						animCurve.setTangent(index, outAngle, outWeight, false);
				}
				
				//	To prevent tangent types from unexpectedly changing, tangent
				//	locking should be the last operation. See the above comments
				//	about fixed tangent types for more information.
				//
				animCurve.setWeightsLocked(index, swLocked);
				animCurve.setTangentsLocked(index, tLocked);
				animCurve.setIsBreakdown (index, isBreakdown);
				
				//	There should be no additional data on this line. Go to the
				//	next line of data.
				//
				clipFile.ignore(INT_MAX, kNewLineChar);
				
				//	Skip any comments.
				//
				advance(clipFile);
				c = clipFile.peek();
		}
		
		//	Ignore the brace that marks the end of the keys block.
		//
		if (c == kBraceRightChar) {
				clipFile.ignore(INT_MAX, kNewLineChar);
		}
		
		//	Ignore the brace that marks the end of the animData block.
		//
		advance(clipFile);
		if (clipFile.peek() == kBraceRightChar) {
				clipFile.ignore(INT_MAX, kNewLineChar);
		} else {
				//	Something is wrong.
				//
				MStatus stringStat;
				MString msg = MStringResource::getString(kMissingBrace, stringStat);
				MGlobal::displayError(msg);
		}
		
		//	Do not set the clipboard with an empty clipboard item.
		//
		if (!animCurveObj.isNull()) {
				item.setAnimCurve(animCurveObj);
		}
		
		//	Delete the copy of the anim curve.
		//
		MGlobal::deleteNode(animCurveObj);
		
		return true;
}

//-------------------------------------------------------------------------
//	Class animWriter
//-------------------------------------------------------------------------

animWriter::animWriter()
//
//	Description:
//		Class constructor.
//
{
}

animWriter::~animWriter()
//
//	Description:
//		Class destructor.
//
{
}

MStatus
animWriter::writeClipboard(	ofstream& animFile,
						   const MAnimCurveClipboard &cb,
						   bool nodeNames /* false */,
						   bool verboseUnits /* false */)
//
//	Description:
//		Write the contents of the clipboard to the ofstream.
//
{
		MStatus status = MS::kFailure;
		
		// Check to see if there is anything on the clipboard at all
		//
		if (cb.isEmpty()) {
				return status;
		}
		
		resetUnits();
		
		// Write out the clipboard information
		//
		if (!writeHeader(animFile)) {
				return (MS::kFailure);
		}
		
		// Now write out each animCurve
		//
		const MAnimCurveClipboardItemArray 	&clipboardArray =
		cb.clipboardItems(&status);
		if (MS::kSuccess != status) {
				return status;
		}
		
		for (unsigned int i = 0; i < clipboardArray.length(); i++) {
				const MAnimCurveClipboardItem &clipboardItem = clipboardArray[i];
				
				MStatus statusInLoop = MS::kSuccess;
				const MObject animCurveObj = clipboardItem.animCurve(&statusInLoop);
				
				//	The clipboard may contain Null anim curves. If a Null anim
				//	curve is returned, it is safe to ignore the error message
				//	and continue to the next anim curve in the list.
				//
				bool placeHolder = false;
				if (MS::kSuccess != statusInLoop || animCurveObj.isNull()) {
						placeHolder = true;
				}
				
				// Write out animCurve information
				//
				if (!writeAnim(animFile, clipboardItem, placeHolder, nodeNames)) {
						return (MS::kFailure);
				}
				
				if (placeHolder) {
						continue;
				}
				
				//	Write out each curve in its specified format.
				//	For now, only the anim curve format.
				//
				if (!writeAnimCurve(animFile, &animCurveObj,
									clipboardItem.animCurveType(),
									verboseUnits)) {
						return (MS::kFailure);
				}
		}
		
		return (MS::kSuccess);
}

bool animWriter::writeHeader(ofstream& clip)
//
//	Description:
//		Writes the header for the file. The header contains the clipboard
//		specific data.
//
{
		if (!clip) {
				return false;
		}
		
		clip << kAnimVersion << kSpaceChar << kAnimVersionString << kSemiColonChar << endl;
		clip << kMayaVersion << kSpaceChar << MGlobal::mayaVersion() << kSemiColonChar << endl;
		
		static MAnimCurveClipboard &clipboard =
		MAnimCurveClipboard::theAPIClipboard();
		
		double startTime = clipboard.startTime().as(timeUnit);
		double endTime = clipboard.endTime().as(timeUnit);
		
		if (startTime != endTime) {
				MString unit;
				animUnitNames::setToShortName(timeUnit, unit);
				clip << kTimeUnit << kSpaceChar << unit << kSemiColonChar << endl;
				animUnitNames::setToShortName(linearUnit, unit);
				clip << kLinearUnit << kSpaceChar << unit << kSemiColonChar << endl;
				animUnitNames::setToShortName(angularUnit, unit);
				clip << kAngularUnit << kSpaceChar << unit << kSemiColonChar << endl;
				clip << kStartTime << kSpaceChar << startTime << kSemiColonChar << endl;
				clip << kEndTime << kSpaceChar << endTime << kSemiColonChar << endl;
		}
		
		float startUnitless = clipboard.startUnitlessInput();
		float endUnitless = clipboard.endUnitlessInput();
		
		if (startUnitless != endUnitless) {
				clip << kStartUnitless << kSpaceChar << startUnitless <<
				kSemiColonChar << endl;
				clip << kEndUnitless << kSpaceChar << endUnitless <<
				kSemiColonChar << endl;
		}
		
		return true;
}

bool animWriter::writeAnim(	ofstream &clip,
						   const MAnimCurveClipboardItem &clipboardItem,
						   bool placeHolder /* false */,
						   bool nodeNames /* false */)
//
//	Description:
//		Write out the anim curve from the clipboard item into the
//		ofstream. The position of the anim curve in the clipboard
//		and the attribute to which it is attached is written out in this
//		method.
//
//		This method returns true if the write was successful.
//
{
		if (!clip) {
				return false;
		}
		
		clip << kAnim;
		
		//	If this is a clipboard place holder then there will be no full
		//	or leaf attribute names.
		//
		if (placeHolder) {
				clip << kSpaceChar << clipboardItem.nodeName().asChar();
		} else {
				clip << kSpaceChar << clipboardItem.fullAttributeName().asChar();
				
				if (nodeNames) {
						clip << kSpaceChar << clipboardItem.leafAttributeName().asChar();
						clip << kSpaceChar << clipboardItem.nodeName().asChar();
				}
		}
		
		unsigned int rowCount, childCount, attrCount;
		clipboardItem.getAddressingInfo(rowCount, childCount, attrCount);
		
		clip << kSpaceChar << rowCount;
		clip << kSpaceChar << childCount;
		clip << kSpaceChar << attrCount;
		clip << kSemiColonChar << endl;
		
		return true;
}

bool animWriter::writeAnimCurve(ofstream &clip,
								const MObject *animCurveObj,
								MFnAnimCurve::AnimCurveType type,
								bool verboseUnits /* false */)
//
//	Description:
//		Write out the anim curve from the clipboard item into the
//		ofstream. The actual anim curve data is written out.
//
//		This method returns true if the write was successful.
//
{
		if (NULL == animCurveObj || animCurveObj->isNull() || !clip) {
				return true;
		}
		
		MStatus status = MS::kSuccess;
		MFnAnimCurve animCurve(*animCurveObj, &status);
		if (MS::kSuccess != status) {
				MString msg = MStringResource::getString(kCouldNotExport, status);
				MGlobal::displayError(msg);
				return false;
		}
		
		clip << kAnimData << kSpaceChar << kBraceLeftChar << endl;
		
		clip << kTwoSpace << kInputString << kSpaceChar <<
		boolInputTypeAsWord(animCurve.isUnitlessInput()) <<
		kSemiColonChar << endl;
		
		clip << kTwoSpace << kOutputString << kSpaceChar <<
		outputTypeAsWord(type) << kSemiColonChar << endl;
		
		clip << kTwoSpace << kWeightedString << kSpaceChar <<
		(animCurve.isWeighted() ? 1 : 0) << kSemiColonChar << endl;
		
		//	These units default to the units in the header of the file.
		//
		if (verboseUnits) {
				clip << kTwoSpace << kInputUnitString << kSpaceChar;
				if (animCurve.isTimeInput()) {
						MString unitName;
						animUnitNames::setToShortName(timeUnit, unitName);
						clip << unitName;
				} else {
						//	The anim curve has unitless input.
						//
						clip << kUnitlessString;
				}
				clip << kSemiColonChar << endl;
				
				clip << kTwoSpace << kOutputUnitString << kSpaceChar;
		}
		
		double conversion = 1.0;
		MString unitName;
		switch (type) {
				case MFnAnimCurve::kAnimCurveTA:
				case MFnAnimCurve::kAnimCurveUA:
				animUnitNames::setToShortName(angularUnit, unitName);
				if (verboseUnits) clip << unitName;
				{
						MAngle angle(1.0);
						conversion = angle.as(angularUnit);
				}
				break;
				case MFnAnimCurve::kAnimCurveTL:
				case MFnAnimCurve::kAnimCurveUL:
				animUnitNames::setToShortName(linearUnit, unitName);
				if (verboseUnits) clip << unitName;
				{
						MDistance distance(1.0);
						conversion = distance.as(linearUnit);
				}
				break;
				case MFnAnimCurve::kAnimCurveTT:
				case MFnAnimCurve::kAnimCurveUT:
				animUnitNames::setToShortName(timeUnit, unitName);
				if (verboseUnits) clip << unitName;
				break;
				default:
				if (verboseUnits) clip << kUnitlessString;
				break;
		}
		if (verboseUnits) clip << kSemiColonChar << endl;
		
		if (verboseUnits) {
				MString angleUnitName;
				animUnitNames::setToShortName(angularUnit, angleUnitName);
				clip << kTwoSpace << kTanAngleUnitString << 
				kSpaceChar << angleUnitName << kSemiColonChar << endl;
		}
		
		clip << kTwoSpace << kPreInfinityString << kSpaceChar <<
		infinityTypeAsWord(animCurve.preInfinityType()) << 
		kSemiColonChar << endl;
		
		clip << kTwoSpace << kPostInfinityString << kSpaceChar <<
		infinityTypeAsWord(animCurve.postInfinityType()) << 
		kSemiColonChar << endl;
		
		clip << kTwoSpace << kKeysString << kSpaceChar << kBraceLeftChar << endl;
		
		// And then write out each keyframe
		//
		unsigned numKeys = animCurve.numKeyframes();
		for (unsigned i = 0; i < numKeys; i++) {
				clip << kTwoSpace << kTwoSpace;
				if (animCurve.isUnitlessInput()) {
						clip << animCurve.unitlessInput(i);
				}
				else {
						clip << animCurve.time(i).value();
				}
				
				// clamp tiny values so that it isn't so small it can't be read in
				//
				double animValue = (conversion*animCurve.value(i));
				if (animBase::isEquivalent(animValue,0.0)) animValue = 0.0;
				clip << kSpaceChar << animValue;
				
				clip << kSpaceChar << tangentTypeAsWord(animCurve.inTangentType(i));
				clip << kSpaceChar << tangentTypeAsWord(animCurve.outTangentType(i));
				
				clip << kSpaceChar << (animCurve.tangentsLocked(i) ? 1 : 0);
				clip << kSpaceChar << (animCurve.weightsLocked(i) ? 1 : 0);
				clip << kSpaceChar << (animCurve.isBreakdown(i) ? 1 : 0);
				
				if (animCurve.inTangentType(i) == MFnAnimCurve::kTangentFixed) {
						MAngle angle;
						double weight;
						animCurve.getTangent(i, angle, weight, true);
						
						clip << kSpaceChar << angle.as(angularUnit);
						clip << kSpaceChar << weight;
				}
				if (animCurve.outTangentType(i) == MFnAnimCurve::kTangentFixed) {
						MAngle angle;
						double weight;
						animCurve.getTangent(i, angle, weight, false);
						
						clip << kSpaceChar << angle.as(angularUnit);
						clip << kSpaceChar << weight;
				}
				
				clip << kSemiColonChar << endl;
		}
		clip << kTwoSpace << kBraceRightChar << endl;
		
		clip << kBraceRightChar << endl;
		
		return true;
}












#include <maya/MFnPlugin.h>
#include <maya/MPxFileTranslator.h>

#include <maya/MSelectionList.h>

#include "animImportExportStrings.h"

#if defined (OSMac_)
#	include <sys/param.h>
extern "C" int strcasecmp (const char *, const char *);
#endif

//-----------------------------------------------------------------------------
//	anim Importer
//-----------------------------------------------------------------------------

const char *const animImportOptionScript = "animImportOptions";
const char *const animImportDefaultOptions =
"targetTime=4;copies=1;option=replace;pictures=0;connect=0;";

// Register all strings used by the plugin C++ code
static MStatus registerMStringResources(void)
{
		MStringResource::registerString(kNothingSelected);
		MStringResource::registerString(kPasteFailed);
		MStringResource::registerString(kAnimCurveNotFound);
		MStringResource::registerString(kInvalidAngleUnits);
		MStringResource::registerString(kInvalidLinearUnits);
		MStringResource::registerString(kInvalidTimeUnits);
		MStringResource::registerString(kInvalidVersion);
		MStringResource::registerString(kSettingToUnit);
		MStringResource::registerString(kMissingKeyword);
		MStringResource::registerString(kCouldNotReadAnim);
		MStringResource::registerString(kCouldNotCreateAnim);
		MStringResource::registerString(kUnknownKeyword);
		MStringResource::registerString(kClipboardFailure);
		MStringResource::registerString(kSettingTanAngleUnit);
		MStringResource::registerString(kUnknownNode);
		MStringResource::registerString(kCouldNotKey);
		MStringResource::registerString(kMissingBrace);
		MStringResource::registerString(kCouldNotExport);
		return MS::kSuccess;
}



animImport::animImport()
: MPxFileTranslator()
{
}

animImport::~animImport()
{
}

void *animImport::creator()
{
		return new animImport();
}

MStatus animImport::reader(	const MFileObject& file,
						   const MString& options,
						   FileAccessMode mode)
{
		MStatus status = MS::kFailure;
		
		MString fileName = file.fullName();
#if defined (OSMac_)
		char fname[MAXPATHLEN];
		strcpy (fname, fileName.asChar());
		ifstream animFile(fname);
#else
		ifstream animFile(fileName.asChar());
#endif
		// 	Parse the options. The options syntax is in the form of
		//	"flag=val;flag1=val;flag2=val"
		//
		MString pasteFlags;
		if (options.length() > 0) {
				//	Set up the flags for the paste command.
				//
				const MString flagTargetTime("targetTime");
				const MString flagTime("time");
				const MString flagCopies("copies");
				const MString flagOption("option");
				const MString flagConnect("connect");
				
				MString copyValue;
				MString flagValue;
				MString connectValue;
				MString timeValue;
				
				//	Start parsing.
				//
				MStringArray optionList;
				MStringArray theOption;
				options.split(';', optionList);
				
				unsigned nOptions = optionList.length();
				for (unsigned i = 0; i < nOptions; i++) {
						
						theOption.clear();
						optionList[i].split('=', theOption);
						if (theOption.length() < 1) {
								continue;
						}
						
						if (theOption[0] == flagCopies && theOption.length() > 1) {
								copyValue = theOption[1];;
						} else if (theOption[0] == flagOption && theOption.length() > 1) {
								flagValue = theOption[1];
						} else if (theOption[0] == flagConnect && theOption.length() > 1) {
								if (theOption[1].asInt() != 0) {
										connectValue += theOption[1];
								}
						} else if (theOption[0] == flagTime && theOption.length() > 1) {
								timeValue += theOption[1];
						}
				}
				
				if (copyValue.length() > 0) {
						pasteFlags += " -copies ";
						pasteFlags += copyValue;
						pasteFlags += " ";
				}
				if (flagValue.length() > 0) {
						pasteFlags += " -option \"";
						pasteFlags += flagValue;
						pasteFlags += "\" ";
				}
				if (connectValue.length() > 0) {
						pasteFlags += " -connect ";
						pasteFlags += connectValue;
						pasteFlags += " ";
				}
				if (timeValue.length() > 0) {
						bool useQuotes = !timeValue.isDouble();
						pasteFlags += " -time ";
						if (useQuotes) pasteFlags += "\"";
						pasteFlags += timeValue;
						if (useQuotes) pasteFlags += "\"";
						pasteFlags += " ";
				}
		}
		
		if (mode == kImportAccessMode) {
				status = importAnim(animFile, pasteFlags);
		}
		
		animFile.close();
		return status;
}

bool animImport::haveReadMethod() const
{
		return true;
}

bool animImport::haveWriteMethod() const
{
		return false;
}

bool animImport::canBeOpened() const
{
		return false;
}

MString animImport::defaultExtension() const
{
		return MString("anim");
}

MPxFileTranslator::MFileKind animImport::identifyFile(
													  const MFileObject& fileName,
													  const char* buffer,
													  short size) const
{
		const char *name = fileName.name().asChar();
		int   nameLength = (int)strlen(name);
		
		if ((nameLength > 5) && !strcasecmp(name+nameLength-5, ".anim")) {
				return kIsMyFileType;
		}
		
		//	Check the buffer to see if this contains the correct keywords
		//	to be a anim file.
		//
		if (strncmp(buffer, "animVersion", 11) == 0) {
				return kIsMyFileType;
		}
		
		return	kNotMyFileType;
}

MStatus
animImport::importAnim(ifstream &animFile, const MString &pasteFlags)
{
		MStatus status = MS::kFailure;
		MAnimCurveClipboard::theAPIClipboard().clear();
		
		//	If the selection list is empty, there is nothing to import.
		//
		MSelectionList sList;
		MGlobal::getActiveSelectionList(sList);
		if (sList.isEmpty()) {
				MString msg = MStringResource::getString(kNothingSelected, status);
				MGlobal::displayError(msg);
				return (MS::kFailure);
		}
		
		if (MS::kSuccess !=
			(status = fReader.readClipboard(animFile,
											MAnimCurveClipboard::theAPIClipboard()))) {
				
				return status;
		}
		
		if (MAnimCurveClipboard::theAPIClipboard().isEmpty()) {
				return (MS::kFailure);
		}
		
		MString command("pasteKey -cb api ");
		command += pasteFlags;
		
		int result;
		if (MS::kSuccess != (status =
							 MGlobal::executeCommand(command, result, false, true))) {
				MString msg = MStringResource::getString(kPasteFailed, status);
				MGlobal::displayError(msg);
				return status;
		}
		
		return status;
}



