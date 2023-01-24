#ifndef DBMIGRATIONS_H
#define DBMIGRATIONS_H

#include <QLatin1String>
#include <QVector>

const auto MIGRATION_1_SOFTWARE_LISTS_SQL = QLatin1String(R"(
    CREATE TABLE software_list(
        id INTEGER PRIMARY KEY,
        name VARCHAR,
        description VARCHAR
    )
)");

const auto MIGRATION_2_SOFTWARE_SQL = QLatin1String(R"(
    CREATE TABLE software(
        id INTEGER PRIMARY KEY,
        software_list_id INTEGER,
        name VARCHAR,
        clone_of VARCHAR,
        supported INTEGER,
        description VARCHAR,
        year INTEGER,
        publisher VARCHAR,
    )
)");

const auto MIGRATION_3_SOFTWARE_INFO_SQL = QLatin1String(R"(
    CREATE TABLE software_info(
        id INTEGER PRIMARY KEY,
        software_id INTEGER,
        name VARCHAR,
        value VARCHAR
    )
)");

const auto MIGRATION_4_SOFTWARE_SHARED_FEAT_SQL = QLatin1String(R"(
    CREATE TABLE software_shared_feat(
        id INTEGER PRIMARY KEY,
        software_id INTEGER,
        name VARCHAR,
        value VARCHAR
    )
)");

const auto MIGRATION_5_SOFTWARE_PART_SQL = QLatin1String(R"(
    CREATE TABLE software_part(
        id INTEGER PRIMARY KEY,
        software_id INTEGER,
        name VARCHAR,
        interface VARCHAR
    )
)");

const auto MIGRATION_6_SOFTWARE_PART_FEATURE_SQL = QLatin1String(R"(
    CREATE TABLE software_part_feature(
        id INTEGER PRIMARY KEY,
        software_part_id INTEGER,
        name VARCHAR,
        value VARCHAR
    )
)");

const auto MIGRATION_7_SOFTWARE_PART_DATA_AREA_SQL = QLatin1String(R"(
    CREATE TABLE software_part_data_area(
        id INTEGER PRIMARY KEY,
        software_part_id INTEGER,
        name VARCHAR,
        size VARCHAR,
        width INTEGER,
        endianness INTEGER
    )
)");

const auto MIGRATION_8_SOFTWARE_PART_DATA_AREA_ROM_SQL = QLatin1String(R"(
    CREATE TABLE software_part_data_area_rom(
        id INTEGER PRIMARY KEY,
        software_part_data_area_id INTEGER,
        name VARCHAR,
        size VARCHAR,
        crc VARCHAR,
        sha1 VARCHAR,
        offset VARCHAR,
        value VARCHAR,
        status INTEGER,
        loadflag INTEGER
    )
)");

const auto MIGRATION_9_SOFTWARE_PART_DISK_AREA_SQL = QLatin1String(R"(
    CREATE TABLE software_part_disk_area(
        id INTEGER PRIMARY KEY,
        software_part_id INTEGER,
        name VARCHAR,
    )
)");

const auto MIGRATION_10_SOFTWARE_PART_DISK_AREA_DISK_SQL = QLatin1String(R"(
    CREATE TABLE software_part_disk_area_disk(
        id INTEGER PRIMARY KEY,
        software_part_disk_area_id INTEGER,
        name VARCHAR,
        sha1 VARCHAR,
        status INTEGER,
        writeable INTEGER
    )
)");

const auto MIGRATION_11_SOFTWARE_PART_DIPSWITCH_SQL = QLatin1String(R"(
    CREATE TABLE software_part_dipswitch(
        id INTEGER PRIMARY KEY,
        software_part_id INTEGER,
        name VARCHAR,
    )
)");
const auto MIGRATION_12_SOFTWARE_PART_DIPSWITCH_DIPVALUE_SQL = QLatin1String(R"(
    CREATE TABLE software_part_dipswitch_dipvalue(
        id INTEGER PRIMARY KEY,
        software_part_dipswitch_id INTEGER,
        name VARCHAR,
        value VARCHAR,
        default INTEGER,
    )
)");

static const QLatin1String* MIGRATION_LIST[] = {
    &MIGRATION_1_SOFTWARE_LISTS_SQL,
    &MIGRATION_2_SOFTWARE_SQL,
    &MIGRATION_3_SOFTWARE_INFO_SQL,
    &MIGRATION_4_SOFTWARE_SHARED_FEAT_SQL,
    &MIGRATION_5_SOFTWARE_PART_SQL,
    &MIGRATION_6_SOFTWARE_PART_FEATURE_SQL,
    &MIGRATION_7_SOFTWARE_PART_DATA_AREA_SQL,
    &MIGRATION_8_SOFTWARE_PART_DATA_AREA_ROM_SQL,
    &MIGRATION_9_SOFTWARE_PART_DISK_AREA_SQL,
    &MIGRATION_10_SOFTWARE_PART_DISK_AREA_DISK_SQL,
    &MIGRATION_11_SOFTWARE_PART_DIPSWITCH_SQL,
    &MIGRATION_12_SOFTWARE_PART_DIPSWITCH_DIPVALUE_SQL
};
#endif // DBMIGRATIONS_H
