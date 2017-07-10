#ifndef HERWIG_INTERFACE_H
#define HERWIG_INTERFACE_H

#include "ThePEG/Repository/Repository.h"

#include "Herwig/API/HerwigUI.h"


class Herwig7API : public Herwig::HerwigUI {
public:

   /// Constructor
   Herwig7API();

   /// Destructor
   ~Herwig7API();


   /// Requested Herwig run mode
   Herwig::RunMode::Mode runMode() const { return(m_runMode); }

   /// Try to resume execution from an earlier interrupted run.
   virtual bool resume() const { return(m_resume); }

   /// Require verbose progress markers
   virtual bool tics() const { return(m_tics); }


   /// Repository name to operate on
   virtual std::string repository() const { return(m_repository); }

   /// Name of the file to be read
   virtual std::string inputfile() const { return(m_inputfile); }
   void inputfile(const std::string inputfile) { m_inputfile = inputfile; }

   /// Name of the setup file to be read, to modify the repository
   virtual std::string setupfile() const { return(m_setupfile); }

   /// A user-defined tag to append to the run name.
   virtual std::string tag() const { return(m_tag); }

   /// An identifier for the integration job to be handled
   virtual std::string integrationList() const { return(m_integrationList); }


   /// Directories from which Herwig reads input files,  will be prepended to the search path.
   virtual const std::vector<std::string> & prependReadDirectories() const { return(m_prependReadDirectories); }

   /// Directories from which Herwig reads input files,  will be appended to the search path.
   virtual const std::vector<std::string> & appendReadDirectories() const { return(m_appendReadDirectories); }


   virtual long N() const { return(m_N); }      /// The number of events to generate
   virtual int seed() const { return(m_seed); } /// The seed to use
   void seed(int seed) { m_seed = seed; }

   virtual int jobs() const { return(m_jobs); } /// The number of jobs to fork
   virtual unsigned int jobSize() const { return(m_jobsize); } /// The number of subprocesses to integrate per integratoin job
   virtual unsigned int maxJobs() const { return(m_maxjobs); } /// The maximum number of integration jobs

  /// Bail out and print usage information
  virtual void quitWithHelp() const {
    std::cerr << "=================================\n";
    std::cerr << "HERE I CAN PUT SOME ERROR MESSAGE\n";
    std::cerr << "=================================\n";
    ThePEG::Repository::cleanup();
    exit( EXIT_FAILURE );
  }

  /// Bail out and be quiet
  virtual void quit() const {
    ThePEG::Repository::cleanup();
    exit( EXIT_FAILURE );
  }

   /// Return the standard out stream to be used
  virtual std::ostream& outStream() const { return(std::cout); }

   /// Return the standard err stream to be used
  virtual std::ostream& errStream() const { return(std::cerr); }

  /// Return the standard in stream to be used
  virtual std::istream& inStream() const { return(std::cin); }


private:

  Herwig::RunMode::Mode m_runMode;

  bool m_resume;
  bool m_tics;

  std::string m_repository;
  std::string m_inputfile;
  std::string m_setupfile;
  std::string m_tag;

  std::string m_integrationList;

  std::vector<std::string> m_prependReadDirectories;
  std::vector<std::string> m_appendReadDirectories;

  long m_N;
  int m_seed;
  int m_jobs;
  unsigned int m_jobsize;
  unsigned int m_maxjobs;

};


#endif