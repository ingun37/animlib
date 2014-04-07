#ifndef animlib_h
#define animlib_h
#include <iostream>
#include <maya/MFnAnimCurve.h>
#include <maya/MAngle.h>
#include <maya/MTime.h>
#include <maya/MDistance.h>
#include <maya/MPxFileTranslator.h>
using namespace std;

class MArgList;

// The base class for the translators.
//
class animBase {
public:
		animBase();
		virtual ~animBase();
		
		enum AnimBaseType			{kAnimBaseUnitless, kAnimBaseTime,
				kAnimBaseLinear, kAnimBaseAngular};
		
		const char *				tangentTypeAsWord(MFnAnimCurve::TangentType);
		MFnAnimCurve::TangentType	wordAsTangentType(char *);
		const char *				infinityTypeAsWord(MFnAnimCurve::InfinityType);
		MFnAnimCurve::InfinityType 	wordAsInfinityType(const char *);
		const char *				outputTypeAsWord(MFnAnimCurve::AnimCurveType);
		MFnAnimCurve::AnimCurveType	typeAsAnimCurveType(AnimBaseType,
														AnimBaseType);
		
		AnimBaseType				wordAsOutputType(const char *);
		AnimBaseType				wordAsInputType(const char *);
		const char *				boolInputTypeAsWord(bool);
		
		double						asDouble(ifstream &);
		char *						asString(ifstream &);
		char *						asWord(ifstream &, bool = false);
		char 						asChar(ifstream &);
		
		bool						isNextNumeric(ifstream &);
		bool						isEquivalent(double, double);
protected:
		void						resetUnits();
		void						advance(ifstream &);
		
		MTime::Unit					timeUnit;
		MAngle::Unit				angularUnit;
		MDistance::Unit				linearUnit;
};

class MAnimCurveClipboard;
class MAnimCurveClipboardItem;
class animReader : public animBase {
public:
		animReader();
		virtual ~animReader();
		
		MStatus	readClipboard(ifstream &, MAnimCurveClipboard&);
protected:
		bool	readAnimCurve(ifstream&, MAnimCurveClipboardItem&);
		void	convertAnglesAndWeights2To3(MFnAnimCurve::AnimCurveType, bool,
											MAngle &, double &);
		void	convertAnglesAndWeights3To2(MFnAnimCurve::AnimCurveType, bool,
											MAngle &, double &);
		
		bool  	convertAnglesFromV2To3;
		bool  	convertAnglesFromV3To2;
		double	animVersion;
};

class animWriter : public animBase {
public:
		animWriter();
		virtual ~animWriter();
		
		MStatus	writeClipboard(	ofstream&, const MAnimCurveClipboard&,
							   bool = false, bool = false);
protected:
		bool	writeHeader(ofstream&);
		bool	writeAnim(	ofstream&, const MAnimCurveClipboardItem&,
						  bool = false, bool = false);
		bool 	writeAnimCurve(	ofstream&, const MObject *,
							   MFnAnimCurve::AnimCurveType,
							   bool = false);
};

class animUnitNames {
public:
		animUnitNames();
		virtual ~animUnitNames();
		
		static void setToLongName(const MAngle::Unit&, MString&);
		static void setToShortName(const MAngle::Unit&, MString&);
		
		static void setToLongName(const MDistance::Unit&, MString&);
		static void setToShortName(const MDistance::Unit&, MString&);
		
		static void setToLongName(const MTime::Unit&, MString&);
		static void setToShortName(const MTime::Unit&, MString&);
		
		static bool setFromName(const MString&, MAngle::Unit&);
		static bool setFromName(const MString&, MDistance::Unit&);
		static bool setFromName(const MString&, MTime::Unit&);
};



// The animImport command object
//
class animImport : public MPxFileTranslator {
public:
		animImport ();
		virtual ~animImport ();
		
		MStatus				doIt (const MArgList &argList);
		static void *		creator ();
		
		virtual MStatus		reader(	const MFileObject& file,
								   const MString& optionsString,
								   FileAccessMode mode);
		
		virtual bool		haveReadMethod() const;
		virtual bool		haveWriteMethod() const;
		virtual bool		canBeOpened() const;
		virtual MString 	defaultExtension() const;
		virtual MFileKind	identifyFile(	const MFileObject& fileName,
										 const char* buffer,
										 short size) const;
private:
		MStatus				importAnim(ifstream&, const MString&);
		MStatus				exportSelected(ofstream&);
		
		animReader			fReader;
};









#endif