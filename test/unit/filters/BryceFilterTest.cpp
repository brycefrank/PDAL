#include <pdal/pdal_test_main.hpp>

#include <filters/BryceFilter.hpp>
#include <io/LasReader.hpp>

#include <pdal/PointView.hpp>
#include <pdal/SpatialReference.hpp>
#include <pdal/StageFactory.hpp>
#include <pdal/util/FileUtils.hpp>

#include "Support.hpp"

using namespace pdal;

TEST(BryceFilterTest, BryceFilterTest_Test_1)

{
    // Create the reader
    Options readerOptions;
    readerOptions.add("filename", Support::datapath("las/1.2-with-color.las"));
    LasReader reader;
    reader.setOptions(readerOptions);

    // Options for filter
    Options o;
    Option length("foo", 1);
    o.add(length);

    BryceFilter b;
    b.setOptions(o);
    b.setInput(reader);

    PointTable table;
    b.prepare(table);
    PointViewSet viewSet = b.execute(table);



}
