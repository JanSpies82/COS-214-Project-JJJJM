#include <limits.h>
#include <stdexcept>
#include "../src/Backup.h"
#include "../src/Memento.h"
#include "gtest/gtest.h"

namespace
{
    TEST(BackupTest, Constructor)
    {
        Backup *backup = new Backup();
        EXPECT_EQ(backup->getMementoCount(), 0);
        delete backup;
    }

    TEST(BackupTest, Destructor)
    {
        Backup *backup = new Backup();
        delete backup;
    }

    TEST(BackupTest, AddMemento)
    {
        Backup *backup = new Backup();
        Memento *m1 = new Memento();
        backup->addMemento(m1);
        EXPECT_EQ(backup->getMementoCount(), 1);
        Memento *m2 = new Memento();
        backup->addMemento(m2);
        EXPECT_EQ(backup->getMementoCount(), 2);
        delete backup;
    }

    TEST(BackupTest, GetMementoPos)
    {
        Backup *backup = new Backup();
        Memento *m1 = new Memento();
        Memento *m2 = new Memento();
        backup->addMemento(m1);
        backup->addMemento(m2);
        EXPECT_EQ(backup->getMemento(), m1);
        EXPECT_EQ(backup->getMementoCount(), 1);
        EXPECT_EQ(backup->getMemento(), m2);
        EXPECT_EQ(backup->getMementoCount(), 0);
        delete backup;
        delete m1;
        delete m2;
    }

    TEST(BackupTest, GetMementoNeg)
    {
        Backup *backup = new Backup();
        try
        {
            backup->getMemento();
            FAIL() << "Expected std::out_of_range";
        }
        catch (std::out_of_range const &err)
        {
            EXPECT_EQ(err.what(), std::string("Backup is empty"));
        }
        catch (...)
        {
            FAIL();
        }
        delete backup;
    }

    TEST(BackupTest, GetMementoCount)
    {
        Backup *backup = new Backup();
        EXPECT_EQ(backup->getMementoCount(), 0);
        Memento *m1 = new Memento();
        backup->addMemento(m1);
        EXPECT_EQ(backup->getMementoCount(), 1);
        Memento *m2 = new Memento();
        backup->addMemento(m2);
        EXPECT_EQ(backup->getMementoCount(), 2);
        delete backup;
    }

    TEST(BackupTest, Clear)
    {
        Backup *backup = new Backup();
        Memento *m1 = new Memento();
        Memento *m2 = new Memento();
        backup->addMemento(m1);
        backup->addMemento(m2);
        backup->clear();
        EXPECT_EQ(backup->getMementoCount(), 0);
        delete backup;
    }

}