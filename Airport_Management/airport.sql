-- MySQL dump 10.13  Distrib 5.5.54, for Win64 (AMD64)
--
-- Host: localhost    Database: airport_management
-- ------------------------------------------------------
-- Server version	5.5.54

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `registration`
--

DROP TABLE IF EXISTS `registration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `registration` (
  `name` varchar(50) DEFAULT NULL,
  `id` varchar(50) NOT NULL,
  `password` varchar(50) DEFAULT NULL,
  `Operating_flight` varchar(50) DEFAULT NULL,
  `Operator_id` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `registration`
--

LOCK TABLES `registration` WRITE;
/*!40000 ALTER TABLE `registration` DISABLE KEYS */;
/*!40000 ALTER TABLE `registration` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `departure`
--

DROP TABLE IF EXISTS `departure`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `departure` (
  `airline` varchar(50) DEFAULT NULL,
  `flight_no` varchar(14) NOT NULL,
  `destination` varchar(50) DEFAULT NULL,
  `depart_hour` int(2) DEFAULT NULL,
  `depart_min` int(2) DEFAULT NULL,
  `check_in` varchar(20) DEFAULT NULL,
  `gate` int(2) DEFAULT NULL,
  `status` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;
--
-- Dumping data for table `departure`
--

LOCK TABLES `departure` WRITE;
/*!40000 ALTER TABLE `departure` DISABLE KEYS */;
/*!40000 ALTER TABLE `departure` ENABLE KEYS */;
UNLOCK TABLES;
--
-- Table structure for table `arrival`
--
DROP TABLE IF EXISTS `arrival`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `arrival` (
  `airline` varchar(50) DEFAULT NULL,
  `flight_no` varchar(14) NOT NULL,
  `arriving` varchar(50) DEFAULT NULL,
  `arrival_hour` int(2) DEFAULT NULL,
  `arrival_min` int(2) DEFAULT NULL,
  `bag_belt` int(2) DEFAULT NULL,
  `status` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `arrival`
--

LOCK TABLES `arrival` WRITE;
/*!40000 ALTER TABLE `arrival` DISABLE KEYS */;
/*!40000 ALTER TABLE `arrival` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-10-11 20:19:38
