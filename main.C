#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>

struct Data
{
  std::string section_name;
  double self;
  double children;
  double total;
};

int main()
{
  std::vector<Data> data;

  data.push_back({"Root", 0.004525, 0.051815, 0.05634});
  data.push_back({"  MooseApp::setup", 1e-05, 0.037072, 0.037082});
  data.push_back({"    FileMesh::init", 3e-06, 0.001548, 0.001551});
  data.push_back({"      FileMesh::readMesh", 0.001548, 0,0.001548});
  data.push_back({"    FileMesh::prepare", 5.1e-05, 0.000192, 0.000243});
  data.push_back({"    FEProblem::init", 6.7e-05, 0.002233, 0.0023});
  data.push_back({"      FEProblem::EquationSystems::Init", 0.002051, 0, 0.002051});
  data.push_back({"  MooseApp::execute", 0, 0.014732, 0.014732});
  data.push_back({"    FEProblem::initialSetup", 0.000376, 0.003268, 0.003644});
  data.push_back({"      FEProblem::projectSolution", 0.000144, 0, 0.000144});
  data.push_back({"    FEProblem::solve", 0.001181, 0.004169, 0.00535});
  data.push_back({"      FEProblem::computeResidualSys", 7e-06, 0.003489, 0.003496});
  data.push_back({"        FEProblem::computeResidualInternal", 1.3e-05, 0.003476, 0.003489});
  data.push_back({"          FEProblem::computeResidualTags", 4.9e-05, 0.003427, 0.003476});
  data.push_back({"            AuxiliarySystem::computeNodalVars", 0.000209, 1e-06, 0.00021});
  data.push_back({"      FEProblem::computeJacobianInternal", 1e-06, 0.000605, 0.000606});
  data.push_back({"        FEProblem::computeJacobianTags", 1e-05, 0.000595, 0.000605});
  data.push_back({"      Console::outputStep", 6e-05, 0, 6e-05});
  data.push_back({"    FEProblem::outputStep", 8.7e-05, 0.005496, 0.005583});
  data.push_back({"      PerfGraphOutput::outputStep", 4.3e-05, 0, 4.3e-05});
  data.push_back({"      Exodus::outputStep", 0.005395, 0, 0.005395});
  data.push_back({"      Console::outputStep", 5.8e-05, 0, 5.8e-05});

  // First - find out the width of the Section column
  unsigned int section_name_size = 0;
  for (auto & row : data)
    if (row.section_name.size() > section_name_size)
      section_name_size = row.section_name.size();

  unsigned int time_size = 10;

  std::cout << "|" << std::setw(section_name_size) << std::left << "Section" << "|" << std::setw(time_size) << std::right << "Self" << "|" << std::setw(time_size) << std::right << "Children" << "|" << std::setw(time_size) << std::right << "Total" << "|\n";

  unsigned int total_chars = section_name_size + 5 + (3 * time_size);

  std::cout << std::string(total_chars, '-') << "\n";


  // Print out each row
//  for (auto & row : data)
//  std::cout << "|" << std::setw(section_name_size) << st

//  std::cout << "|" << std::setw(5) << std::left << "Dog" << "|" << std::endl;
}
