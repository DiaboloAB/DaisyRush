import { BadRequestException, Injectable, InternalServerErrorException } from '@nestjs/common';
import { PrismaService } from './prisma/prisma.service';
import { Record as PrismaRecord } from '@prisma/client';


@Injectable()
export class AppService {
  constructor(
    private prisma: PrismaService
  ) {}


  getScoreboard(): Promise<PrismaRecord[]> {
    const records = this.prisma.record.findMany({
      orderBy: {
        timestamp: 'desc'
      }
    });

    if (!records) {
      throw new InternalServerErrorException('Failed to fetch records');
    }

    return records;
  }

  addScore(record: PrismaRecord): Promise<PrismaRecord> {
    if (!record.name || !record.timestamp) {
      throw new BadRequestException('Invalid record');
    }
    const newRecord = this.prisma.record.create({
      data: {
        name: record.name,
        timestamp: record.timestamp
      }
    });

    if (!newRecord) {
      throw new InternalServerErrorException('Failed to create record');
    }

    return newRecord;
  }
}
