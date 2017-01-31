/******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
 *                                                                            *
 * This file is part of APEX 3.                                               *
 *                                                                            *
 * APEX 3 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 3 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 3.  If not, see <http://www.gnu.org/licenses/>.            *
 *****************************************************************************/

#ifndef _EXPORL_SRC_LIB_APEXMAIN_L34STIMULUS_L34DEVICE_H_
#define _EXPORL_SRC_LIB_APEXMAIN_L34STIMULUS_L34DEVICE_H_

#include "apexdata/map/apexmap.h"

#include "stimulus/outputdevice.h"

#include "l34datablock.h"

#include <QString>

namespace apex{

    namespace data{
        class L34DeviceData;
    }

    class PluginNotFoundException:
        public ApexStringException {
    public:
        PluginNotFoundException(const QString& message):
          ApexStringException(message){};
        };

    namespace stimulus{


        class ApexNreSocketInterface;


        typedef std::map<QString, L34XMLData> SequenceMap;


        class L34Device : public OutputDevice
        {
            Q_DECLARE_TR_FUNCTIONS(L34Device)
        public:
            L34Device( const QString& ac_sHost,
                data::L34DeviceData* ac_params);

            ~L34Device();

            void AddFilter    ( Filter&    ac_Filter       );
            void AddInput     ( const DataBlock& ac_DataBlock    );
            void SetSequence  ( const DataBlockMatrix* ac_pSequence );
            //void RemoveInput  ( const QString&   ac_sDataBlockID );
            void RemoveAll    (                                  );

            /*void Play         ( const QString&  ac_sDataBlockID,
            const int       ac_nFlags        );*/
            void PlayAll      ( void );
            void Stop         ( const QString&  ac_sDataBlockID,
                const int       ac_nFlags        );
            void StopAll      (       );
            bool Done         ( const QString&  ac_sDataBlockID  );
            bool AllDone      (                                  );

            const QString& GetModule() const
            { return sc_sL34Device; }

            virtual bool SetParameter ( const QString& type, const int channel, const QVariant& value );

            void RestoreParametersImpl();

            virtual void Reset();
            virtual void Prepare();

            virtual void SetSilenceBefore(double);

            void SetMap (data::ApexMap* p_map) ;

            virtual bool CanSequence() const
            {
                return true;
            }

            //virtual const QString GetResultXML() const;
            virtual QString GetEndXML() const;

        private:


            bool waitUntil( const QString& STATE1,const QString& STATE2, int timeout );
            bool waitUntil( const QString& STATE, int timeout );

            void SendPowerup(  );

            void LoadPlugin();

        private:
            void showStatus();


            QScopedPointer<ApexNreSocketInterface> m_pDevice;


            QString m_host;
            bool m_bPlaying;
            // is the device ready to be started?
            bool m_bReady;
            data::ApexMap* m_pMap;
            int m_iTriggerType;
            int m_nDeviceNr;
            // how many powerup frames to send before starting streaming
            int m_nPowerupCount;
            // is powerup already sent for this sequence?
            bool m_bPowerupSent;
            // length of the current stimulus in us
            long m_stimulusLength;
            // timer that will be started when the stimulus starts
            QTime m_timeSinceStart;
            // current output volume, in % (0-100)
            float m_volume;
        };
    }
}

#endif //#ifndef _EXPORL_SRC_LIB_APEXMAIN_L34STIMULUS_L34DEVICE_H_