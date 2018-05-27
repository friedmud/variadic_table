#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <tuple>

struct Data
{
  std::string section_name;
  double self;
  double children;
  double total;
};

/**
 * Class that has a header and a string first column
 */
/*
class PerfGraphTable
{
public:
  PerfGraphTable(unsigned int num_data_columns, unsigned int data_column_width)
      : _data_columns(num_data_columns), _data_column_width(data_column_width)
  {}

protected:
  std::vector<std::string> _section_name_column;

  std::vector<std::vector<double>> _data_columns;

  unsigned int _data_column_width;
};
*/

template<class... Ts>
class PerfGraphTable
{
public:
  void addRow(std::tuple<Ts...> data)
  {
    _data.push_back(data);
  }

  void print()
  {
    for (auto & row : _data)
    {
      print_each(row);
      std::cout << std::endl;
    }
  }

protected:

// From https://stackoverflow.com/a/26908596
template<typename TupleType>
void print_each(TupleType&&, std::integral_constant<size_t, std::tuple_size<typename std::remove_reference<TupleType>::type >::value>) {}

template<std::size_t I, typename TupleType, typename = typename std::enable_if<I!=std::tuple_size<typename std::remove_reference<TupleType>::type>::value>::type >
void print_each(TupleType&& t, std::integral_constant<size_t, I>)
{
  std::cout << std::get<I>(t) << "|";
  print_each(std::forward<TupleType>(t), std::integral_constant<size_t, I + 1>());
}

template<typename TupleType>
void print_each(TupleType&& t)
{
  print_each(std::forward<TupleType>(t), std::integral_constant<size_t, 0>());
}



  template<typename T>
  void print_helper( unsigned int column, const T & x ) { std::cout << x << "|"; }

  std::vector<std::tuple<Ts...>> _data;
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

  unsigned int total_chars = section_name_size + 5 + (3 * time_size);

  // Line above the header
  std::cout << std::string(total_chars, '-') << "\n";

  // Header
  std::cout << "|" << std::setw(section_name_size) << std::left << "Section" << "|" << std::setw(time_size) << std::right << "Self" << "|" << std::setw(time_size) << std::right << "Children" << "|" << std::setw(time_size) << std::right << "Total" << "|\n";

  // Line under the header
  std::cout << std::string(total_chars, '-') << "\n";

  // Print out each row
  for (auto & row : data)
    std::cout << "|" << std::setw(section_name_size) << std::left << row.section_name << "|" << std::setw(time_size) << std::right << row.self << "|" << std::setw(time_size) << std::right << row.children << "|" << std::setw(time_size) << std::right << row.total << "|\n";

  // Bottom line
  std::cout << std::string(total_chars, '-') << "\n";

//  std::cout << "|" << std::setw(section_name_size) << st

//  std::cout << "|" << std::setw(5) << std::left << "Dog" << "|" << std::endl;

  PerfGraphTable<std::string, double, double> pgt;

  pgt.addRow({"stuff", 1.2, 3.5});

  pgt.print();
}
