#include "Herwig7API.h"

#include "Herwig/API/HerwigAPI.h"

#include "ThePEG/Repository/Repository.h"
#include "ThePEG/Utilities/DynamicLoader.h"
#include "ThePEG/Repository/EventGenerator.h"
#include "ThePEG/EventRecord/Event.h"
// #include "ThePEG/Handlers/SamplerBase.h"

#include <string>

Herwig7API::Herwig7API()
  : m_inputfile("Herwig.run"),
    m_setupfile(""),
    m_N(1),
    m_seed(1),
    m_jobs(1),
    m_maxjobs(1)
{

  std::cout << "Calling the constructor\n";

  // Possibly add more paths to dynamic loader with ThePEG::DynamicLoader::prependPath() and ThePEG::DynamicLoader::appendPath()
  // All external dependencies should work via the LD_LIBRARY_PATH

  // Possibly add more paths to search the list of directories with ThePEG::Repository::prependReadDir() or ThePEG::Repository::appendReadDir()
  // This may be relevant for gridpack generation outside of the grid followed by subsequent running of the event generation in the grid

  // Load default repository
  std::cout << "getting environment variable 'HERWIG_PATH'... " << std::flush;
  std::string strHerwigPath = getenv("HERWIG_PATH");
  std::cout << "done" << std::endl << std::flush;
  std::cout << "found value '" << strHerwigPath << "'" << std::endl << std::flush;
  std::cout << "attempting to load the default repository from path '" << strHerwigPath << "/share/Herwig/HerwigDefaults.rpo'... " << std::flush;
  ThePEG::Repository::load(strHerwigPath+"/share/Herwig/HerwigDefaults.rpo");
  std::cout << "done" << std::endl << std::flush;

}


Herwig7API::~Herwig7API() {
  ThePEG::Repository::cleanup();
}


int main(){

  std::cout << "starting interface...\n";

  unsigned N = 10;
  int seed = 1;
  std::string runfile = "LHC-FxFx-Rivet-TTbar1-001-100.0.run";
  // std::string runfile = "Herwig-Builtin.run";
  // std::string runfile = "Herwig-Matchbox.run";
  // std::string runfile = "Herwig-Matchbox-OpenLoops.run";

  // Initialise the interface instance
  std::cout << "Initialising the interface instance..." << std::flush;
  Herwig7API api;
  std::cout << "done" << std::endl << std::flush;

  // Set the runfile name
  std::cout << "Setting the runfile name to '" << runfile << "'..." << std::flush;
  api.inputfile(runfile);
  std::cout << "done" << std::endl << std::flush;

  // Set the random number seed
  std::cout << "Setting the random seed to '" << seed << "'... " << std::flush;
  api.seed(seed);
  std::cout << "done" << std::endl << std::flush;

  // Prepare the run from the runfile
  std::cout << "Preparing the run from runfile '" << runfile << "'... " << std::flush;
  ThePEG::EGPtr generator = Herwig::API::prepareRun(api);
  std::cout << "done" << std::endl << std::flush;

  // // Do a full run
  // std::cout << "starting full run..." << std::endl << std::flush;
  // Herwig::API::run(api);
  // std::cout << "finished doing a full run" << std::endl << std::flush;

  // Generate events one by one
  ThePEG::EventPtr event;
  for (unsigned n = 1; n <= N; n++){
    std::cout << "generating event #" << n << " out of " << N << "..." << std::endl << std::flush;
    event = generator->shoot();
    std::cout << "finished generating event #" << n << std::endl << std::flush;
  }
  generator->finalize();
  ThePEG::Repository::cleanup();

}
