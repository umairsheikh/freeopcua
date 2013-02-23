/// @author Alexander Rykovanov 2010
/// @email rykovanov.as@gmail.com
/// @brief cppunit tests.
/// @license GNU GPL/LGPL
///
/// Distributed under the GNU GPL/LGPL License
/// (See accompanying file LICENSE or copy at 
/// http://www.gnu.org/copyleft/gpl.html)
///
/// $Id:  $
/// $Date: $
/// $Revision: $


#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <exception>
#include <iostream>

#include <managers/common_managers/common_managers.h>
#include <common/addons_core/addon_manager.h>

#include "../addon.h"



extern "C" void RegisterServerManagers()
{
}

int main(int argc, char** argv)
{
  try
  {
    std::shared_ptr<Common::AddonsManager> manager = Common::GetAddonsManager();
    Common::RegisterCommonManagers();
    Gps::RegisterDeviceManager();
    Common::GetAddonsManager()->Start();

    CPPUNIT_NS::TestResult controller;
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);
    CPPUNIT_NS::CompilerOutputter outputter(&result, CPPUNIT_NS::stdCOut());
    outputter.write();
    return result.wasSuccessful() ? 0 : -1;
  }
  catch(const std::exception& exc)
  {
    std::cout << exc.what() << std::endl;
  }
  catch(...)
  {
    std::cout << "Unknown exception." << std::endl;
  }
  return -1;
}
