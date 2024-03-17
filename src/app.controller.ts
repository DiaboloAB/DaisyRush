import { Body, Controller, Get, Put } from '@nestjs/common';
import { AppService } from './app.service';

import { Record as PrismaRecord } from '@prisma/client';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get()
  getScoreboard(): Promise<PrismaRecord[]> {
    return this.appService.getScoreboard();
  }

  @Put()
  addScore(@Body() record: PrismaRecord): Promise<PrismaRecord> {
    return this.appService.addScore(record);
  }
}
